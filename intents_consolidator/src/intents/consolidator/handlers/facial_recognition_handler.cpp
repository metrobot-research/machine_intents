/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#include <memory>

#include "machine_intents_interfaces/msg/facial_detection_result.hpp"

#include "intents_consolidator/intents/consolidator/handlers/facial_detection_handler.hpp"
#include "intents_consolidator/datastructures/embedding.hpp"

namespace intents
{
namespace consolidator
{

FacialRecognitionResult::FacialRecognitionResult(
  const machine_intents_interfaces::msg::FacialRecognitionResult * msg)
{
  embedding_ = std::make_unique<datastructures::Embedding>(msg->embedding);
}


void FacialRecognitionHandler::Merge(FacialRecognitionResult & res, State & state)
{
  //
  return false;
}

}  // namespace consolidator
}  // namespace intents
