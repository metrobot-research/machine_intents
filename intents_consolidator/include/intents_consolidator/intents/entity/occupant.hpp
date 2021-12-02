/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__ENTITY__OCCUPANT_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__ENTITY__OCCUPANT_HPP_

#include <utility>
#include <vector>

#include "boost/date_time/posix_time/posix_time.hpp"
#include "intents_consolidator/intents/entity/entity.hpp"
#include "intents_consolidator/intents/entity/pose.hpp"

namespace intents
{
namespace entity
{

class Occupant : public ::intents::entity::Entity
{
  using TimestampedPose = std::pair<boost::posix_time::ptime, ::intents::entity::Pose>;

public:
  Occupant(std::unique_ptr<datastructures::Embedding> embedding){embedding_ = std::move(embedding);}

  const std::vector<TimestampedPose> & PoseHistory() {return pose_history_;}

  const datastructures::Embedding & GetEmbedding() {return * embedding_;}

  void add_timestamped_pose(
    const boost::posix_time::ptime time,
    const ::intents::entity::Pose & pose)
  {
    pose_history_.emplace_back(time, pose);
  }

  void SetEmbedding(std::unique_ptr<datastructures::Embedding> embedding) {
    embedding_ = std::move(embedding);
  }

private:
  std::vector<TimestampedPose> pose_history_;
  std::unique_ptr<datastructures::Embedding> embedding_;
};

}  // namespace entity
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__ENTITY__OCCUPANT_HPP_
