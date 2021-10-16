#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::Matrix;

struct embedding_msg {
    int height; // Total number of rows
	int  row_step; // Number of floats in a row
	double* data;  // Actual point data, size is (row_step*height)
	std::string comparison_type; // Either cosine or distance
	std::string type; // Unique type of the embedding
};

class Embedding
{
    public:
        Embedding(struct embedding_msg *msg) : m(msg->data, msg->height, msg->row_step) {
            std::cout << m << std::endl;
            comparison_type = msg->comparison_type;
            type = msg->type;
            // m(msg->data, msg->height, msg->row_step);
            // m.resize(msg->height, msg->row_step);
        }
        
        double compare(Embedding *other) {
            // Return Fro
            if (comparison_type == "distance") {
                Eigen::MatrixXd temp = m - other->m;
                // std::cout << temp << std::endl;
                return temp.norm();
            }
            if (comparison_type == "cosine") {return 0.0;}
            return 0.0;
        }
    private:
        Eigen::Map<Eigen::MatrixXd> m;
        std::string comparison_type;
        std::string type;
};

int main()
{
    double a[12] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    struct embedding_msg msg = {2, 6, a, "distance", "test"};
    double b[12] = {7.0, 8.0, 9.0, 10.0, 5.0, 6.0};
    struct embedding_msg msg2 = {2, 6, b, "distance", "test"};
    Embedding test(&msg);
    Embedding test2(&msg2);
    std::cout << test2.compare(&test)<< std::endl;
}
// Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>