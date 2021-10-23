/**
 * Copyright (c) 2021 The MetroBot Authors
 */

#ifndef INTENTS_CONSOLIDATOR__DATASTRUCTURES__EMBEDDINGS_HPP_
#define INTENTS_CONSOLIDATOR__DATASTRUCTURES__EMBEDDINGS_HPP_

#include <Eigen/Dense>
#include "machine_intents_interfaces/msg/embedding.hpp"

namespace datastructures
{

class Embedding
{
public:
  explicit Embedding(machine_intents_interfaces::msg::Embedding & msg);
  double compare(const Embedding & other);

private:
  Eigen::Map<Eigen::VectorXd> vector;
  std::string comparison_type;
  std::string type;
};

} // namespace datastructures

#endif // INTENTS_CONSOLIDATOR__DATASTRUCTURES__EMBEDDINGS_HPP_
