/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#include "intents_consolidator/consolidator_node.hpp"

#include "rclcpp/rclcpp.hpp"

namespace machine_intents
{
namespace intents_consolidator
{

ConsolidatorNode::ConsolidatorNode(const rclcpp::NodeOptions & options)
: Node{"consolidator_node", options},
  state_pub_{create_publisher<std_msgs::msg::String>("state", 10)},
  observation_sub_{create_subscription<std_msgs::msg::String>(
      "observation", 10,
      std::bind(&ConsolidatorNode::ObservationCallback, this, std::placeholders::_1))} {}

void ConsolidatorNode::ObservationCallback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "Received message: %s", msg->data.c_str());
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
