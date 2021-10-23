#include <iostream>
#include <vector>
#include <cassert>

#include <Eigen/Dense>
#include "intents_consolidator/datastructures/embeddings.hpp"
#include "machine_intents_interfaces/msg/embedding.hpp"

namespace datastructures
{

Embedding::Embedding(machine_intents_interfaces::msg::Embedding & msg)
: vector(msg.data.data(), (long int) msg.data.size())
{
  comparison_type = msg.comparison_type;
  type = msg.type;
}

double Embedding::compare(const Embedding & other)
{
  assert(other.vector.size() == vector.size());
  // Return L2 norm of the difference between this vector and other.
  if (comparison_type == "distance") {
    Eigen::VectorXd temp = vector - other.vector;
    return temp.norm();
  }
  // Return the cosine angle difference between this matrix and other.
  if (comparison_type == "cosine") {
    return vector.dot(other.vector) / (vector.norm() * other.vector.norm());
  }
  return 0.0;
}
} // namespace datastructures
