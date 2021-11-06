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
    const std::lock_guard<std::mutex> lock{queue_mutex_};
    if (queue_.empty()) {
      continue;
    }
    Result res {std::move(queue_.front())};
    queue_.pop();
    if (res.facial_recognition) {
      facial_recognition_handler_.Merge(*res.facial_recognition, *state_);
    }
    // more else if statements for different result types here
  }
}

void Consolidator::AddResult(const std::unique_ptr<Result> res)
{
  // Add elem to the queue
  queue_.push(std::move(*res));
}

}  // namespace consolidator
}  // namespace intents
