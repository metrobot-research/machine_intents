#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_CONSOLIDATOR_STATE_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_CONSOLIDATOR_STATE_HPP

#include <memory>
#include <vector>

#include "intents_consolidator/intents/entity/occupant.hpp"
#include "intents_consolidator/intents/entity/point_of_interest.hpp"

namespace intents {
namespace consolidator {

class State {
 public:
  std::vector<std::unique_ptr<::intents::entity::Occupant>>& Occupants() {
    return occupants_;
  }

  std::vector<std::unique_ptr<::intents::entity::POI>>& PointsOfInterest() {
    return points_of_interest_;
  }

 private:
  std::vector<std::unique_ptr<::intents::entity::Occupant>> occupants_;
  std::vector<std::unique_ptr<::intents::entity::POI>> points_of_interest_;
};

}  // namespace consolidator
}  // namespace intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_CONSOLIDATOR_STATE_HPP
