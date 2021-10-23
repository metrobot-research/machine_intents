#include <iostream>
#include <vector>
#include <cassert>

#include <Eigen/Dense>
#include "intents_consolidator/datastructures/embedding.hpp"
#include "machine_intents_interfaces/msg/embedding.hpp"

namespace datastructures
{

Embedding::Embedding(machine_intents_interfaces::msg::Embedding & msg)
: vector_(msg.data.data(), (long int) msg.data.size())
{
  comparison_type_ = msg.comparison_type;
  type_ = msg.type;
}

double Embedding::Compare(const Embedding & other) const
{
  assert(other.vector_.size() == vector_.size());
  assert(other.comparison_type_ == comparison_type_);

  // Return L2 norm of the difference between this vector and other.
  if (comparison_type_ == "distance") {
    Eigen::VectorXd diff = vector_ - other.vector_;
    return diff.norm();
  }
  // Return the cosine similarity between this matrix and other.
  if (comparison_type_ == "cosine") {
    return vector_.dot(other.vector_) / (vector_.norm() * other.vector_.norm());
  }
  return 0.0;
}

} // namespace datastructures
