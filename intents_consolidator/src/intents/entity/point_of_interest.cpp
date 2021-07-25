#include "intents_consolidator/intents/entity/point_of_interest.hpp"

#include "intents_consolidator/intents/entity/location.hpp"

namespace intents {
namespace entity {
bool POI::Near(const POI other) {
  double center_distance = Loc().DistanceTo(other.Loc());
  return center_distance <= InfluenceRadius() + other.InfluenceRadius();
}

bool POI::Near(const Location loc) {
  double center_distance = Loc().DistanceTo(loc);
  return center_distance <= InfluenceRadius();
}
}  // namespace entity
}  // namespace intents
