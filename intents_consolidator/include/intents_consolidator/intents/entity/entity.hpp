#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_ENTITY_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_ENTITY_HPP

#include "absl/time/time.h"
#include "boost/uuid/random_generator.hpp"
#include "boost/uuid/uuid.hpp"
#include "intents_consolidator/intents/entity/location.hpp"
#include "intents_consolidator/intents/entity/size.hpp"

namespace intents {
namespace entity {
class POI;

class Entity {
 public:
  Entity() : uuid_(boost::uuids::random_generator()()) {}
  virtual ~Entity() {}

  const boost::uuids::uuid& UUID() const { return uuid_; }
  const absl::Time& LastSeen() const { return last_seen_; }
  const Location& Loc() const { return location_; }

  void SetLastSeen(const absl::Time& seen_at) {
    last_seen_ = std::max(seen_at, last_seen_);
  }

  void SetLocation(const Location& location) { location_ = location; }

  virtual bool Near(const POI other) = 0;
  virtual bool Near(const Location loc) = 0;

 private:
  const boost::uuids::uuid uuid_;
  absl::Time last_seen_;
  Location location_;
};

}  // namespace entity
}  // namespace intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_ENTITY_ENTITY_HPP
