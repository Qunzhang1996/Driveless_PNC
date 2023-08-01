#include <iostream>
#include <Eigen/Dense>
#include "kalman_filter.h" // Include the KalmanFilter class header
#include "matplotlibcpp.h" // Include the plotting library

namespace plt = matplotlibcpp;

using namespace Eigen;

int main() {
    // Initialize the Kalman filter
    Matrix2d A;
    A << 1.0, 0.1,
         0.0, 1.0;

    Matrix2d B;
    B << 0.005, 0.0,
         0.0, 0.1;

    Matrix2d H = Matrix2d::Identity(); // Measurement matrix

    Matrix2d Q;
    Q << 0.01, 0.0,
         0.0, 0.01;

    Matrix2d R;
    R << 0.25, 0.0,
         0.0, 0.25;

    KalmanFilter kf(A, B, H, Q, R);

    // Set initial state and covariance
    Vector2d initial_state;
    initial_state << 0.0, 0.0;

    Matrix2d initial_state_covariance;
    initial_state_covariance << 1.0, 0.0,
                                0.0, 1.0;

    kf.init(initial_state, initial_state_covariance);

    // Time step and duration
    double dt = 0.1; // 100ms
    double duration = 20.0; // 20 seconds
    int num_steps = static_cast<int>(duration / dt);

    // Input step signal (u_k)
    Vector2d input_signal;
    input_signal << 1.0, 1.0; // Example: constant input signal

    // Vectors to store true state, estimated state, and noisy measurements
    std::vector<double> time_points, true_state_x, true_state_y, estimated_state_x, estimated_state_y, noisy_x, noisy_y;

    // Perform Kalman filter prediction and update for each time step
    for (int i = 0; i < num_steps; ++i) {
        // Predict the next state
        kf.predict(input_signal);

        // Generate noisy measurement (z_k) from the true state (x_k)
        Vector2d true_state = kf.getState();
        Vector2d measurement_noise;
        measurement_noise << 1 * std::sin(0.1 * i), 1 * std::cos(0.1 * i); // Example: noisy measurement noise
        Vector2d noisy_measurement = H * true_state + measurement_noise;

        // Update the state estimate using the noisy measurement
        kf.correct(noisy_measurement);

        // Store data for visualization
        time_points.push_back(i * dt);
        true_state_x.push_back(true_state[0]);
        true_state_y.push_back(true_state[1]);
        estimated_state_x.push_back(kf.getState()[0]);
        estimated_state_y.push_back(kf.getState()[1]);
        noisy_x.push_back(noisy_measurement[0]);
        noisy_y.push_back(noisy_measurement[1]);
    }

    // Visualize the state evolution and noisy measurements for x
    plt::figure();
    plt::named_plot("True x", time_points, true_state_x, "r-");
    plt::named_plot("Estimated x", time_points, estimated_state_x, "g--");
    plt::named_plot("Noisy x", time_points, noisy_x, "b-");
    plt::xlabel("Time (seconds)");
    plt::ylabel("State Value");
    plt::title("State Evolution of x with Noisy Measurements (Kalman Filter)");
    plt::legend();
    plt::show();

    // Visualize the state evolution and noisy measurements for y
    plt::figure();
    plt::named_plot("True y", time_points, true_state_y, "r-");
    plt::named_plot("Estimated y", time_points, estimated_state_y, "g--");
    plt::named_plot("Noisy y", time_points, noisy_y, "b-");
    plt::xlabel("Time (seconds)");
    plt::ylabel("State Value");
    plt::title("State Evolution of y with Noisy Measurements (Kalman Filter)");
    plt::legend();
    plt::show();

    return 0;
}
