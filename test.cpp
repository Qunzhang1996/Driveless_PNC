#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace std;
int main() {
    // Define a dense matrix
    Eigen::MatrixXd AA(3, 3);
    AA << 1, 0, 1,
          0, 2, 0,
          1, 0, 3;

    // Convert to sparse representation
    Eigen::SparseMatrix<double> AA_sparse = AA.sparseView();

    // Print the non-zero values of the sparse matrix
    cout<<AA_sparse<<endl;

    return 0;
}
