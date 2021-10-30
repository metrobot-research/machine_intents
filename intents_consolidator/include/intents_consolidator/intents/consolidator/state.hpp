/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__STATE_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__STATE_HPP_

#include <memory>
#include <vector>

#include "intents_consolidator/intents/entity/occupant.hpp"

namespace intents
{
namespace consolidator
{

class State
{
public:
  std::vector<std::unique_ptr<::intents::entity::Occupant>> & Occupants()
  {
    return occupants_;
  }

private:
  std::vector<std::unique_ptr<::intents::entity::Occupant>> occupants_;
};

}  // namespace consolidator
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__CONSOLIDATOR__STATE_HPP_
