/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__ENTITY__POINT_OF_INTEREST_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__ENTITY__POINT_OF_INTEREST_HPP_

#include <vector>

#include "boost/uuid/uuid.hpp"
#include "intents_consolidator/intents/entity/entity.hpp"
#include "intents_consolidator/intents/entity/goal_type.hpp"

namespace intents
{
namespace entity
{

class POI : public ::intents::entity::Entity
{
public:
  POI(const boost::uuids::uuid & type_uuid, double radius)
  : poi_type_(type_uuid), influence_radius_(radius) {}

  const boost::uuids::uuid & POIType() const {return poi_type_;}
  const std::vector<::intents::entity::GoalType> & SupportedGoalTypes() const
  {
    return supported_goal_types_;
  }
  double InfluenceRadius() const {return influence_radius_;}
  void SetInfluenceRadius(double influence_radius)
  {
    influence_radius_ = influence_radius;
  }

  bool Near(const POI other) override;
  bool Near(const Location loc) override;

private:
  boost::uuids::uuid poi_type_;
  std::vector<::intents::entity::GoalType> supported_goal_types_;
  double influence_radius_;
  // TODO(JS): What other metadata?
};

}  // namespace entity
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__ENTITY__POINT_OF_INTEREST_HPP_
