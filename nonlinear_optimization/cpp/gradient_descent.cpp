#include<iostream>
#include<Eigen/Dense>
using namespace Eigen;
void gradient_descent(VectorXd &theta, const MatrixXd &x, const VectorXd &y, double learning_rate, int epochs){
    int m = x.rows();
    for(int i=0;i<epochs;i++){
        VectorXd error = (y - x*theta);
        MatrixXd gradient = -2.0/m*x.transpose()*error;
        theta-=learning_rate*gradient;
    }

};


int main() {
    // Sample linear regression dataset
    Eigen::VectorXd X(5);
    X << 1.0, 2.0, 3.0, 4.0, 5.0;
    Eigen::VectorXd y(5);
    y << 3.0, 6.0, 8.0, 10.0, 12.0; // y = 2*x + 1

    // Set hyperparameters for linear regression
    double learning_rate = 0.1;
    int epochs = 1000;

    // Initialize coefficients for the linear regression model (intercept, slope)
    Eigen::VectorXd theta(2);
    theta << 0.0, 0.0;

    // Add a column of ones to X for the intercept term
    Eigen::MatrixXd X_b(5, 2);
    X_b << Eigen::VectorXd::Ones(5), X;

    // Fit the linear regression model
    gradient_descent(theta, X_b, y, learning_rate, epochs);

    // Print the coefficients (intercept, slope)
    std::cout << "Optimal Parameters for the Linear Regression Model (Intercept, Slope): "
              << theta[0] << ", " << theta[1] << std::endl;

    return 0;
}
