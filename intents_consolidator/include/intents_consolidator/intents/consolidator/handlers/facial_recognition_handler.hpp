/**
 * Copyright (c) 2021 The MetroBot Authors
 */
#ifndef INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__HANDLERS__FACIAL_DETECTION_HANLDER_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__HANDLERS__FACIAL_DETECTION_HANLDER_HPP_

#include <memory>

#include "machine_intents_interfaces/msg/facial_recognition_result.hpp"

#include "intents_consolidator/datastructures/embedding.hpp"
#include "intents_consolidator/intents/consolidator/state.hpp"

namespace intents
{
namespace consolidator
{

class FacialRecognitionResult
{
public:
  FacialRecognitionResult(const machine_intents_interfaces::msg::FacialRecognitionResult * msg);

private:
  std::unique_ptr<datastructures::Embedding> embedding_;
};

class FacialRecognitionHandler
{
public:
  FacialRecognitionHandler(const FacialRecognitionHandler &) = delete;
  FacialRecognitionHandler & operator=(const FacialRecognitionHandler &) = delete;

  bool Merge(FacialRecognitionResult & res, State & state);
};

}  // namespace consolidator
}  // namespace intents

#endif // INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__HANDLERS__FACIAL_DETECTION_HANLDER_HPP_
