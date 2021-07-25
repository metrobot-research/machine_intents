#ifndef ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_CONSOLIDATOR_RESULT_OBJECT_CLASSIFICATION_RESULT_HPP
#define ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_CONSOLIDATOR_RESULT_OBJECT_CLASSIFICATION_RESULT_HPP

#include "boost/uuid/uuid.hpp"
#include "intents_consolidator/intents/consolidator/result/result.hpp"
#include "intents_consolidator/intents/entity/location.hpp"

namespace intents {
namespace consolidator {

class ObjectClassificationResult : public Result {
 public:
  const boost::uuids::uuid& LabelUUID() const { return label_uuid_; }

  void SetLabelUUID(const boost::uuids::uuid& uuid) { label_uuid_ = uuid; }

  double InfluenceRadius() const { return influence_radius_; }

  void SetInfluenceRadius(double radius) { influence_radius_ = radius; }

 private:
  boost::uuids::uuid label_uuid_;
  double influence_radius_;  // TODO(JS): More precise volume system?
};

}  // namespace consolidator
}  // namespace intents

#endif  // ROS_WS_INTENTS_WS_SRC_MACHINE_INTENTS_INTENTS_CONSOLIDATOR_INCLUDE_INTENTS_CONSOLIDATOR_INTENTS_CONSOLIDATOR_RESULT_OBJECT_CLASSIFICATION_RESULT_HPP
