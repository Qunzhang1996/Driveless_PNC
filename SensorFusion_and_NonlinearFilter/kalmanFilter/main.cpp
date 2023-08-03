#include <iostream>
#include <Eigen/Dense>
#include "kalmanFilter/KalmanFilter.h" // Include the KalmanFilter class header
#include "matplotlibcpp.h" // Include the plotting library

namespace plt=matplotlibcpp;
using namespace Eigen;
#include<cmath>
Vector2d continuousInputSignal(double t) {
    double amplitude = 1.0; // Amplitude of the signal
    double frequency = 1.0; // Frequency of the signal (in Hz)
    double u_x = amplitude * std::sin(2 * M_PI * frequency * t);
    double u_y = amplitude * std::cos(2 * M_PI * frequency * t);
    
    Vector2d input_signal;
    input_signal << u_x, u_y;
    return input_signal;
}

int main(){
    Matrix2d A;
    A<<1.0, 0.1,
       0.0, 1.0;
    Matrix2d B;
    B<<0.005,0.0,
       0.0,  0.1;
    Matrix2d H=Matrix2d::Identity();
    Matrix2d Q;
    Q<<0.01,0.0
        0.0,0.01;
    Matrix2d R;
    R<<0.25, 0.0,
        0.0,0.25;
    KalmanFilter kf(A,B,H,Q,R);
    Vector2d initial_state;
    initial_state << 0.0, 0.0;
    Matrix2d initial_state_covariance;
    initial_state_covariance << 1.0, 0.0,
                                0.0, 1.0;
    kf.init(initial_state,initial_state_covariance);
    double dt = 0.1;
    double duration = 20.0;
    int num_steps = static_cast<int>(duration/dt);
    std::vector<double> time_points,true_state_x,true_state_y,
                        estimate_state_x,estimate_state_y,noisy_x,noisy_y;
    for(int i =0;i<num_steps;i++){
        Vector2d input_signal = continuousInputSignal(i*dt);
        kf.predict(input_signal);
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
    return 0;
}