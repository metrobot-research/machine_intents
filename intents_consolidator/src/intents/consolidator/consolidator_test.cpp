#include "intents_consolidator/intents/consolidator/consolidator.hpp"

#include <iostream>

#include "absl/memory/memory.h"
#include "boost/uuid/random_generator.hpp"
#include "gtest/gtest.h"
#include "intents_consolidator/intents/consolidator/state.hpp"
#include "intents_consolidator/intents/entity/location.hpp"

namespace intents {
namespace consolidator {
namespace {

using ::intents::entity::Location;
using ::intents::entity::POI;

const Location kObject0Location = Location(1, 1, 1);
const Location kObject1Location = Location(5, 5, 5);
const Location kObject2Location = Location(10, 10, 10);

class MergeResultTest : public ::testing::Test {
 protected:
  void SetUp() override {
    state_ = absl::make_unique<State>();
    state_ptr_ = state_.get();

    auto object1 =
        absl::make_unique<POI>(::boost::uuids::random_generator()(), 1.0);
    object1->SetLocation(kObject0Location);
    state_->PointsOfInterest().push_back(std::move(object1));

    auto object2 =
        absl::make_unique<POI>(::boost::uuids::random_generator()(), 2.0);
    object2->SetLocation(kObject1Location);
    state_->PointsOfInterest().push_back(std::move(object2));

    auto object3 =
        absl::make_unique<POI>(::boost::uuids::random_generator()(), 3.0);
    object3->SetLocation(kObject2Location);
    state_->PointsOfInterest().push_back(std::move(object3));

    consolidator_ = absl::make_unique<Consolidator>(std::move(state_));
  }

  std::unique_ptr<State> state_;
  State* state_ptr_;
  std::unique_ptr<Consolidator> consolidator_;
};

TEST_F(MergeResultTest, ObjectClassificationResult_MatchAndNoMatch) {
  auto loc_to_match = Location(1.5, 1.5, 1.5);
  auto fragment_to_match = ObjectClassificationResult();
  fragment_to_match.SetLocation(Location(1.5, 1.5, 1.5));
  fragment_to_match.SetInfluenceRadius(1.0);

  auto loc_no_match = Location(15, 15, 15);
  auto fragment_no_match = ObjectClassificationResult();
  fragment_no_match.SetLocation(Location(15, 15, 15));
  fragment_no_match.SetInfluenceRadius(1.0);

  EXPECT_TRUE(consolidator_->MergeResult(fragment_to_match));
  EXPECT_FALSE(consolidator_->MergeResult(fragment_no_match));
  EXPECT_EQ(state_ptr_->PointsOfInterest().size(), 4);

  auto& first = state_ptr_->PointsOfInterest().at(0);
  EXPECT_EQ(first->Loc(), loc_to_match);

  auto& second = state_ptr_->PointsOfInterest().at(1);
  EXPECT_EQ(second->Loc(), kObject1Location);

  auto& third = state_ptr_->PointsOfInterest().at(2);
  EXPECT_EQ(third->Loc(), kObject2Location);

  auto& fourth = state_ptr_->PointsOfInterest().at(2);
  EXPECT_EQ(fourth->Loc(), loc_no_match);
}

}  // namespace
}  // namespace consolidator
}  // namespace intents
