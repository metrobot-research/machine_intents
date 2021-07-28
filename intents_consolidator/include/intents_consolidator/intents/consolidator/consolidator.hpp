/**
 * Copyright (c) 2021 The MetroBot Authors
 */
#ifndef INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__CONSOLIDATOR_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__CONSOLIDATOR_HPP_

#include <memory>
#include <utility>
#include <vector>

#include "intents_consolidator/intents/consolidator/result/object_classification_result.hpp"
#include "intents_consolidator/intents/consolidator/result/result.hpp"
#include "intents_consolidator/intents/consolidator/state.hpp"

namespace intents
{
namespace consolidator
{

class Consolidator
{
public:
  Consolidator() = default;
  explicit Consolidator(std::unique_ptr<State> && state)
  : state_(std::move(state)) {}

  bool UpdateState(const std::unique_ptr<Result> result);

  Consolidator(const Consolidator &) = delete;
  Consolidator & operator=(const Consolidator &) = delete;

  // TODO(rithvikp): Make this private again and add a friend class for testing.
  bool MergeResult(
    const ::intents::consolidator::ObjectClassificationResult & result);

private:
  const std::unique_ptr<State> state_;
};

}  // namespace consolidator
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__CONSOLIDATOR_HPP_
