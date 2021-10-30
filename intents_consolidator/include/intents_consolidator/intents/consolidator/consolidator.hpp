/**
 * Copyright (c) 2021 The MetroBot Authors
 */
#ifndef INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__CONSOLIDATOR_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__CONSOLIDATOR_HPP_

#include <memory>
#include <utility>
#include <vector>

#include "intents_consolidator/intents/consolidator/handlers/facial_recognition_handler.hpp"
#include "intents_consolidator/intents/consolidator/state.hpp"

namespace intents
{
namespace consolidator
{

struct Result
{
  std::unique_ptr<FacialRecognitionResult> facial_detection;
};

class Consolidator
{
public:
  Consolidator();

  Consolidator(const Consolidator &) = delete;
  Consolidator & operator=(const Consolidator &) = delete;

  // Continually read from the result queue and update the internal state, periodically writing
  // out to durable storage.
  void Loop();

  // Add the provided result to the queue. This method may block for a period of time.
  void AddResult(const std::unique_ptr<Result> res);

private:
  std::unique_ptr<State> state_;
};

}  // namespace consolidator
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__CONSOLIDATOR_HPP_
