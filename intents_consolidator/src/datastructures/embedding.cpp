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
  // Return Frobenius norm of the difference between this matrix and other
  if (comparison_type == "distance") {
    Eigen::VectorXd temp = vector - other.vector;
    return temp.norm();
  }
  // Return cosine angle difference between this matrix and other
  if (comparison_type == "cosine") {
    return vector.dot(other.vector) / (vector.norm() * other.vector.norm());
  }
  return 0.0;
}
} // namespace datastructures

int main()
{
  std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  machine_intents_interfaces::msg::Embedding msg;
  msg.data = a;
  msg.comparison_type = "cosine";
  msg.type = "test";

  std::vector<double> b = {7.0, 8.0, 9.0, 10.0, 5.0, 6.0};
  machine_intents_interfaces::msg::Embedding msg2;
  msg2.data = b;
  msg2.comparison_type = "cosine";
  msg2.type = "test";

  datastructures::Embedding test(msg);
  a[4] = 100000.0;
  // std::cout << test.vector << std::endl;
  datastructures::Embedding test2(msg2);
  // std::cout << a.size() << std::endl;
  // std::cout << b.size() << std::endl;

  std::cout << "Similiarity : " << test2.compare(test) << std::endl;

  return 0;
}
