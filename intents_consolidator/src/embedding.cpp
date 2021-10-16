#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <cassert>

using Eigen::Matrix;

struct embedding_msg {
	std::vector<double> data;  // Actual point data, size is (row_step*height)
	std::string comparison_type; // Either cosine or distance
	std::string type; // Unique type of the embedding
};

class Embedding
{
    public:
        Embedding(struct embedding_msg &msg) : vector{msg.data.data(), msg.data.size()} {
            //std::cout << vector << std::endl;
            comparison_type = msg.comparison_type;
            type = msg.type;
        }
        
        double compare(const Embedding &other) {
            assert(other.vector.size() != vector.size());
            std::cout << "The two matrices are not the same size\n";
            // Return Frobenius norm of the difference between this matrix and other
            if (comparison_type == "distance") {
                Eigen::VectorXd temp = vector - other.vector;
                // std::cout << temp << std::endl;
                return temp.norm();
            }
            if (comparison_type == "cosine") {
                return 0.0;
            }
            return 0.0;
        }
        Eigen::Map<Eigen::VectorXd> vector;
    private:
        
        std::string comparison_type;
        std::string type;
};

int main()
{
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    struct embedding_msg msg = {a, "distance", "test"};
    std::vector<double> b = {7.0, 8.0, 9.0, 10.0, 5.0, 6.0};
    struct embedding_msg msg2 = {b, "distance", "test"};
    Embedding test(msg);
    a[4] = 100000.0;
    std::cout << test.vector << std::endl;
    Embedding test2(msg2);
    std::cout << test2.compare(test)<< std::endl;
}