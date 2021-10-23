#!/usr/bin/env python
import time

import face_recognition
import rclpy
from rclpy.node import Node
import cv2
from cv_bridge import CvBridge

from machine_intents_interfaces.msg import DetectionResult
from sensor_msgs.msg import Image as msg_Image


class FaceDetection(Node):
    def __init__(self):
        super().__init__("face_detection")
        self.publisher_ = self.create_publisher(
            DetectionResult, "face_detection", 10)
        self.subscription = self.create_subscription(
            msg_Image, "sensor_msgs/Image", self.camera_callback, 10)

    def camera_callback(self, data):
        cv_image = self.bridge.imgmsg_to_cv2(data, data.encoding)
        small_frame = cv2.resize(cv_image, (0, 0), fx=0.25, fy=0.25)
        # Convert the image from BGR color (which OpenCV uses) to RGB color (which face_recognition uses)
        rgb_small_frame = small_frame[:, :, ::-1]

        face_locations = face_recognition.face_locations(rgb_small_frame)
        face_encodings = face_recognition.face_encodings(
            rgb_small_frame, face_locations)

        for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
            msg = DetectionResult()
            msg.header.stamp = self.get_clock().now().to_msg()
            # find center point and unscale
            msg.x = (left + right) / 2 * 4
            msg.y = (top + bottom) / 2 * 4
            #msg.z = cv_image[msg.y, msg.x]
            msg.embedding.comparison_type = "distance"
            msg.embedding.data = face_encodings[0].tolist()
            msg.embedding.is_bigendian = False
            msg.embedding.point_step = 4
            msg.embedding.row_step = 512
            self.publisher_.publish(msg)
            self.get_logger().info("Face Detected!")
        self.get_logger().info(f"{len(face_locations)} faces detected.")


def main():
    rclpy.init()
    node = FaceDetection()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
