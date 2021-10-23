/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__RESULT__RESULT_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__RESULT__RESULT_HPP_

#include <string>
#include <vector>

#include "boost/date_time/posix_time/posix_time.hpp"
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

  const boost::posix_time::ptime Timestamp() const {return timestamp_;}

  const ::intents::entity::Location & Loc() const {return location_;}

  void SetLocation(const ::intents::entity::Location & loc) {location_ = loc;}

private:
  std::string source_;
  double confidence_;  // TODO(JS): Decide if this is an appropriate
                       // representation for confidence
  boost::posix_time::ptime timestamp_;
  ::intents::entity::Location location_;
};

}  // namespace consolidator
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__RESULT__RESULT_HPP_
