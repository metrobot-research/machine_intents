/**
 * Copyright (c) 2021 The MetroBot Authors
 */
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "machine_intents_interfaces/msg/facial_recognition_result.hpp"

#include "intents_consolidator/consolidator_node.hpp"

namespace machine_intents
{
namespace intents_consolidator
{

ConsolidatorNode::ConsolidatorNode(const rclcpp::NodeOptions & options)
: Node{"consolidator_node", options},
  observation_sub_{create_subscription<machine_intents_interfaces::msg::FacialRecognitionResult>(
      "facial_recognition_result", 10,
      std::bind(&ConsolidatorNode::FacialRecognitionResultCallback, this, std::placeholders::_1))}
{
}

void ConsolidatorNode::FacialRecognitionResultCallback(
  const machine_intents_interfaces::msg::FacialRecognitionResult::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "Received message");
}

}  // namespace intents_consolidator
}  // namespace machine_intents

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::executors::MultiThreadedExecutor exec;

  rclcpp::NodeOptions options;
  auto node = std::make_shared<machine_intents::intents_consolidator::ConsolidatorNode>(options);

  exec.add_node(node);

  exec.spin();

  return 0;
}

// Register as component
#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(machine_intents::intents_consolidator::ConsolidatorNode)
