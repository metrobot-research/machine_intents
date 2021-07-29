/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__ENTITY__POSE_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__ENTITY__POSE_HPP_

#include "intents_consolidator/intents/entity/location.hpp"

namespace intents
{
namespace entity
{

class Pose
{
  explicit Pose(::intents::entity::Location anchor)
  : body_anchor_(anchor) {}

  const ::intents::entity::Location & BodyAnchor() const {return body_anchor_;}

  void SetBodyAnchor(const ::intents::entity::Location & anchor)
  {
    body_anchor_ = anchor;
  }

private:
  // TODO(JS): Some representation of the actual pose itself
  ::intents::entity::Location body_anchor_;
};

}  // namespace entity
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__ENTITY__POSE_HPP_
