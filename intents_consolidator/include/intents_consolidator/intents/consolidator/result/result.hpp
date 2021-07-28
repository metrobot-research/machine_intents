/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__RESULT__RESULT_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__RESULT__RESULT_HPP_

#include <string>
#include <vector>

#include "absl/memory/memory.h"
#include "absl/time/time.h"
#include "intents_consolidator/intents/entity/location.hpp"

namespace intents
{
namespace consolidator
{

class Result
{
public:
  const std::string & Source() const {return source_;}

  double Confidence() const {return confidence_;}

  const absl::Time & Timestamp() const {return timestamp_;}

  const ::intents::entity::Location & Loc() const {return location_;}

  void SetLocation(const ::intents::entity::Location & loc) {location_ = loc;}

private:
  std::string source_;
  double confidence_;  // TODO(JS): Decide if this is an appropriate
                       // representation for confidence
  absl::Time timestamp_;
  ::intents::entity::Location location_;
};

}  // namespace consolidator
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__RESULT__RESULT_HPP_
