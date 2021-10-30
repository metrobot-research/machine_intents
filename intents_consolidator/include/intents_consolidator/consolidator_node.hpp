/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_
#define INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "machine_intents_interfaces/msg/facial_recognition_result.hpp"

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
  void FacialRecognitionResultCallback(
    const machine_intents_interfaces::msg::FacialRecognitionResult::SharedPtr msg);

  std::unique_ptr<intents::consolidator::Consolidator> consolidator_;

  rclcpp::Subscription<machine_intents_interfaces::msg::FacialRecognitionResult>::SharedPtr
    observation_sub_;

};

}  // namespace intents_consolidator
}  // namespace machine_intents

#endif  // INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_
