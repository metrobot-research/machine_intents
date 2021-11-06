/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#include <memory>

#include "machine_intents_interfaces/msg/facial_recognition_result.hpp"

#include "intents_consolidator/intents/consolidator/handlers/facial_recognition_handler.hpp"
#include "intents_consolidator/datastructures/embedding.hpp"

namespace intents
{
namespace consolidator
{

FacialRecognitionResult::FacialRecognitionResult(
   machine_intents_interfaces::msg::FacialRecognitionResult& msg)
{
  embedding_ = std::make_unique<datastructures::Embedding>(msg.embedding);
}


void FacialRecognitionHandler::Merge(FacialRecognitionResult & res, State & state)
{
  //
  return;
}

}  // namespace consolidator
}  // namespace intents
