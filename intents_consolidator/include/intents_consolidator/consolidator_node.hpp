#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_CONSOLIDATOR_NODE_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_CONSOLIDATOR_NODE_HPP

#include "intents/entity/location.hpp"
#include "rclcpp/rclcpp.hpp"

namespace machine_intents {

namespace intents_consolidator {

class ConsolidatorNode : public rclcpp::Node {
 public:
  ConsolidatorNode() : Node("consolidator_node") {}
};

}  // namespace intents_consolidator

}  // namespace machine_intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_CONSOLIDATOR_NODE_HPP
