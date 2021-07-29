/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__ENTITY__OCCUPANT_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__ENTITY__OCCUPANT_HPP_

#include <utility>
#include <vector>

#include "absl/time/time.h"
#include "intents_consolidator/intents/entity/entity.hpp"
#include "intents_consolidator/intents/entity/point_of_interest.hpp"
#include "intents_consolidator/intents/entity/pose.hpp"

namespace intents
{
namespace entity
{

class Occupant : public ::intents::entity::Entity
{
  using TimestampedPose = std::pair<absl::Time, ::intents::entity::Pose>;

public:
  Occupant()
  : pose_history_() {}

  const std::vector<TimestampedPose> & PoseHistory() {return pose_history_;}

  void add_timestamped_pose(
    const absl::Time & time,
    const ::intents::entity::Pose & pose)
  {
    pose_history_.emplace_back(time, pose);
  }

  bool Near(const POI other) override {return false;}
  bool Near(const Location loc) override {return false;}

private:
  std::vector<TimestampedPose> pose_history_;
};

}  // namespace entity
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__ENTITY__OCCUPANT_HPP_
