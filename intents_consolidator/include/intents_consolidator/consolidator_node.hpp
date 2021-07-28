/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_
#define INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_

#include "intents/entity/location.hpp"
#include "rclcpp/rclcpp.hpp"

namespace machine_intents
{

namespace intents_consolidator
{

class ConsolidatorNode : public rclcpp::Node
{
public:
  ConsolidatorNode()
  : Node("consolidator_node") {}
};

}  // namespace intents_consolidator

}  // namespace machine_intents

#endif  // INTENTS_CONSOLIDATOR__CONSOLIDATOR_NODE_HPP_
