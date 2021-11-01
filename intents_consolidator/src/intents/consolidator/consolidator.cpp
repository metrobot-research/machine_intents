/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#include <algorithm>
#include <memory>
#include <vector>

#include "intents_consolidator/intents/consolidator/consolidator.hpp"
#include "intents_consolidator/intents/consolidator/state.hpp"

namespace intents
{
namespace consolidator
{

Consolidator::Consolidator()
{
  state_ = std::make_unique<State>();
}

void Consolidator::Loop()
{
  while (true) {
    // Pop elem and then run merge on non-null type in result
    Result res;
    if (queue_.pop(res)) {
      
    }
  }
}

void Consolidator::AddResult(const std::unique_ptr<Result> res)
{
  // Add elem to the queue
  queue_.push(*res);
}

}  // namespace consolidator
}  // namespace intents
