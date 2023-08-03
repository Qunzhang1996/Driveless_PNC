#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace Eigen;

// Define the true quadratic function: f(x) = a*x^2 + b*x + c
double trueQuadraticFunction(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Generate synthetic data from the true quadratic function with some noise
void generateSyntheticData(const std::vector<double>& x_values, const double true_a, const double true_b, const double true_c,
                           std::vector<double>& y_values, const double noise_stddev) {
    y_values.clear();
    for (const auto& x : x_values) {
        double noise = noise_stddev * (2.0 * std::rand() / RAND_MAX - 1.0); // Random noise in the range [-noise_stddev, noise_stddev]
        y_values.push_back(trueQuadraticFunction(true_a, true_b, true_c, x) + noise);
    }
}

// Define the quadratic function: f(x) = a*x^2 + b*x + c
double quadraticFunction(const Vector3d& coefficients, double x) {
    double a = coefficients[0];
    double b = coefficients[1];
    double c = coefficients[2];
    return a * x * x + b * x + c;
}

// Compute the Jacobian matrix for the quadratic function
MatrixXd computeJacobian(const Vector3d& coefficients, const std::vector<double>& x_data) {
    int num_data_points = x_data.size();
    double a = coefficients[0];
    double b = coefficients[1];
    double c = coefficients[2];

    MatrixXd jacobian(num_data_points, 3);
    for (int i = 0; i < num_data_points; ++i) {
        double x = x_data[i];
        jacobian(i, 0) = x * x; // df/da = x^2
        jacobian(i, 1) = x;     // df/db = x
        jacobian(i, 2) = 1.0;   // df/dc = 1
    }
    return jacobian;
}

int main() {
    // True coefficients for the quadratic function
    double true_a = 2.0;
    double true_b = -3.0;
    double true_c = 1.5;

    // Generate synthetic data with noise
    const int num_data_points = 100;
    const double noise_stddev = 0.5;
    std::vector<double> x_data;
    std::vector<double> y_data;
    for (int i = 0; i < num_data_points; ++i) {
        double x = 5.0 * i / num_data_points; // Generate data points from 0 to 5
        x_data.push_back(x);
    }
    generateSyntheticData(x_data, true_a, true_b, true_c, y_data, noise_stddev);

    // Initial guess for coefficients [a, b, c]
    Vector3d coefficients;
    coefficients << 1.0, 1.0, 1.0;

    // Gauss-Newton iterations
    const int max_iterations = 100;
    const double tolerance = 1e-6;
    for (int iter = 0; iter < max_iterations; ++iter) {
        // Compute the residuals (error vector)
        VectorXd residuals(num_data_points);
        for (int i = 0; i < num_data_points; ++i) {
            residuals[i] = y_data[i] - quadraticFunction(coefficients, x_data[i]);
        }

        // Compute the Jacobian matrix
        MatrixXd jacobian = computeJacobian(coefficients, x_data);

        // Gauss-Newton update
        Vector3d update = (jacobian.transpose() * jacobian).inverse() * jacobian.transpose() * residuals;
        coefficients += update;

        // Check for convergence
        if (update.norm() < tolerance) {
            std::cout << "Converged after " << iter + 1 << " iterations.\n";
            break;
        }
    }

    // Output the true and estimated coefficients
    std::cout << "True coefficients: a = " << true_a << ", b = " << true_b << ", c = " << true_c << std::endl;
    std::cout << "Estimated coefficients: a = " << coefficients[0] << ", b = " << coefficients[1] << ", c = " << coefficients[2] << std::endl;

    return 0;
}
