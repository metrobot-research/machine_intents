/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_
#define INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "intents/consolidator/consolidator.hpp"

namespace machine_intents
{
namespace intents_consolidator
{

class ConsolidatorNode : public rclcpp::Node
{
public:
  explicit ConsolidatorNode(const rclcpp::NodeOptions & options);

private:
  void ObservationCallback(const std_msgs::msg::String::SharedPtr msg);

  intents::consolidator::Consolidator consolidator_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_pub_;

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr observation_sub_;

};

}  // namespace intents_consolidator
}  // namespace machine_intents

#endif  // INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_
