#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_POSE_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_POSE_HPP

#include "intents_consolidator/intents/entity/location.hpp"

namespace intents {
namespace entity {

class Pose {
  Pose(::intents::entity::Location anchor) : body_anchor_(anchor) {}

  const ::intents::entity::Location& BodyAnchor() const { return body_anchor_; }

  void SetBodyAnchor(const ::intents::entity::Location& anchor) {
    body_anchor_ = anchor;
  }

 private:
  // TODO(JS): Some representation of the actual pose itself
  ::intents::entity::Location body_anchor_;
};

}  // namespace entity
}  // namespace intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_POSE_HPP
