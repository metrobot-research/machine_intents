/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#include <memory>
#include <cstdlib>

#include "machine_intents_interfaces/msg/facial_detection_result.hpp"

#include "intents_consolidator/intents/consolidator/handlers/facial_detection_handler.hpp"
#include "intents_consolidator/datastructures/embedding.hpp"

namespace intents
{
namespace consolidator
{

FacialRecognitionResult::FacialRecognitionResult(
  const machine_intents_interfaces::msg::FacialRecognitionResult * msg, const entity::Pose pose)
{
  embedding_ = std::make_unique<datastructures::Embedding>(msg->embedding);
  pose_ = pose
}


void FacialRecognitionHandler::Merge(FacialRecognitionResult & res, State & state)
{
  double acceptable_error = 0.02;
  bool matched = false;
  for(auto & element : state.Occupants()) {
    double comparison = res.embedding_.Compare(element.GetEmbedding());
    if(abs(comparison) < acceptable_error) {
      matched = true;
      element.SetEmbedding(std::move(res.GetEmbedding()));
      element.add_timestamped_pose(time, res.GetPose());
      break;
    }
  }
  if(!matched) {
    auto * occupant = make_unique_ptr<entity::Occupant>(std::move(res.GetEmbedding());
    occupant.add_timestamped_pose(time, res.GetPose());
    state.AddOccupant(occupant);
  }
  // return false;
}

}  // namespace consolidator
}  // namespace intents
