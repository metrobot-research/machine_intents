/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__ENTITY__GOAL_TYPE_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__ENTITY__GOAL_TYPE_HPP_

#include "boost/uuid/uuid.hpp"

namespace intents
{
namespace entity
{

enum class GoalType
{
  kIdle,
  kObtain,
  kInterfaceWith,  // Occupant <-> POI
  kInteractWith    // Occupant <-> Occupant
};

}  // namespace entity
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__ENTITY__GOAL_TYPE_HPP_
