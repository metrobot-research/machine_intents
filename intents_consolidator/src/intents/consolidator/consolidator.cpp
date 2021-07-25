#include "intents_consolidator/intents/consolidator/consolidator.hpp"

#include <algorithm>

#include "absl/memory/memory.h"
#include "intents_consolidator/intents/consolidator/result/object_classification_result.hpp"
#include "intents_consolidator/intents/consolidator/result/result.hpp"

namespace intents {
namespace consolidator {

using ::intents::consolidator::ObjectClassificationResult;
using ::intents::consolidator::State;
using ::intents::entity::POI;

bool Consolidator::UpdateState(const std::unique_ptr<Result> result) {
  const auto& result_type = typeid(*result);

  if (result_type == typeid(ObjectClassificationResult)) {
    return MergeResult(*static_cast<ObjectClassificationResult*>(result.get()));
  } else {  // Failed to recognize the type of this result
    return false;
  }
}

bool Consolidator::MergeResult(const ObjectClassificationResult& result) {
  // Coarse scan through POIs by location
  std::vector<POI*> candidate_matches;
  for (const auto& poi : state_->PointsOfInterest()) {
    if (poi->Near(result.Loc())) {
      candidate_matches.push_back(poi.get());
    }
  }

  // Fine scan through POIs by other attributes of this
  // ObjectClassificationResult
  std::remove_if(candidate_matches.begin(), candidate_matches.end(),
                 [result](POI* candidate) {
                   return result.LabelUUID() == candidate->POIType();
                 });

  if (candidate_matches.empty()) {
    state_->PointsOfInterest().push_back(absl::make_unique<POI>(
        POI(result.LabelUUID(), result.InfluenceRadius())));
    return false;
  }
  auto* match = candidate_matches[0];
  match->SetLocation(result.Loc());
  match->SetLastSeen(result.Timestamp());
  return true;
}

}  // namespace consolidator
}  // namespace intents
