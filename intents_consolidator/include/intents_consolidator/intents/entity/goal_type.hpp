#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_GOAL_TYPE_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_GOAL_TYPE_HPP

#include "boost/uuid/uuid.hpp"

namespace intents {
namespace entity {

enum class GoalType {
  kIdle,
  kObtain,
  kInterfaceWith,  // Occupant <-> POI
  kInteractWith    // Occupant <-> Occupant
};

}  // namespace entity
}  // namespace intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_GOAL_TYPE_HPP
