/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__DATASTRUCTURES__EMBEDDINGS_HPP_
#define INTENTS_CONSOLIDATOR__DATASTRUCTURES__EMBEDDINGS_HPP_

#include <string>

#include <Eigen/Dense>
#include "machine_intents_interfaces/msg/embedding.hpp"

namespace datastructures
{

class Embedding
{
public:
  explicit Embedding(machine_intents_interfaces::msg::Embedding & msg);

  // Given two embeddings, compare them via comparison_type
  // (vectors must be same length and have the same comparison_type)
  double Compare(const Embedding & other) const;

private:
  Eigen::Map<Eigen::VectorXd> vector_;
  std::string comparison_type_;
  std::string type_;
};

} // namespace datastructures

#endif // INTENTS_CONSOLIDATOR__DATASTRUCTURES__EMBEDDINGS_HPP_
