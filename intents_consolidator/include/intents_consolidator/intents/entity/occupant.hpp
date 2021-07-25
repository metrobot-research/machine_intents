#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_OCCUPANT_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_OCCUPANT_HPP

#include <vector>

#include "absl/time/time.h"
#include "intents_consolidator/intents/entity/entity.hpp"
#include "intents_consolidator/intents/entity/point_of_interest.hpp"
#include "intents_consolidator/intents/entity/pose.hpp"

namespace intents {
namespace entity {

class Occupant : public ::intents::entity::Entity {
  using TimestampedPose = std::pair<absl::Time, ::intents::entity::Pose>;

 public:
  Occupant() : pose_history_() {}

  const std::vector<TimestampedPose>& PoseHistory() { return pose_history_; }

  void add_timestamped_pose(const absl::Time& time,
                            const ::intents::entity::Pose& pose) {
    pose_history_.emplace_back(time, pose);
  }

  bool Near(const POI other) override { return false; }
  bool Near(const Location loc) override { return false; }

 private:
  std::vector<TimestampedPose> pose_history_;
};

}  // namespace entity
}  // namespace intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_OCCUPANT_HPP
