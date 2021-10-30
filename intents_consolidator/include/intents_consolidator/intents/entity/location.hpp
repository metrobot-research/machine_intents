/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#include <cmath>
#include <string>

#include "boost/format.hpp"

#ifndef INTENTS_CONSOLIDATOR__INTENTS__ENTITY__LOCATION_HPP_
#define INTENTS_CONSOLIDATOR__INTENTS__ENTITY__LOCATION_HPP_

namespace intents
{
namespace entity
{

class Location
{
public:
  Location() = default;
  Location(double x, double y, double z)
  : x_(x), y_(y), z_(z) {}

  double X() const {return x_;}
  double Y() const {return y_;}
  double Z() const {return z_;}

  void SetLocation(const double x, const double y, const double z)
  {
    x_ = x;
    y_ = y;
    z_ = z;
  }

  double DistanceTo(const Location l) const
  {
    auto x_diff = x_ - l.X();
    auto y_diff = y_ - l.Y();
    auto z_diff = z_ - l.Z();
    return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
  }

  bool operator==(Location l) const
  {
    return l.X() == x_ && l.Y() == y_ && l.Z() == z_;
  }

  std::string DebugString() const
  {
    auto fmt = boost::format("X: %.2d\tY: %.2d\tZ: %.2d") % x_ % y_ % z_;
    return fmt.str();
  }

private:
  double x_;
  double y_;
  double z_;
};

//std::ostream & operator<<(std::ostream & stream, const Location & loc)
//{
//return stream << loc.DebugString();
//}

//Location operator-(const Location l1, const Location l2)
//{
//return Location(l1.X() - l2.X(), l1.Y() - l2.Y(), l1.Z() - l2.Z());
//}

}  // namespace entity
}  // namespace intents

#endif  // INTENTS_CONSOLIDATOR__INTENTS__ENTITY__LOCATION_HPP_
