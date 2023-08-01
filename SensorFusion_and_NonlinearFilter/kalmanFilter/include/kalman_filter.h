#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include <Eigen/Dense>

class KalmanFilter {
public:
    // Constructor
    KalmanFilter(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
                 const Eigen::MatrixXd& H, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R);

    // Initialize the Kalman filter with the initial state and initial state covariance
    void init(const Eigen::VectorXd& initial_state, const Eigen::MatrixXd& initial_state_covariance);

    // Perform the prediction step of the Kalman filter
    void predict(const Eigen::VectorXd& control_input);

    // Perform the correction step of the Kalman filter
    void correct(const Eigen::VectorXd& measurement);

    // Get the current state estimate
    Eigen::VectorXd getState() const;

private:
    // Kalman filter parameters
    Eigen::MatrixXd A_; // State transition matrix
    Eigen::MatrixXd B_; // Control input matrix
    Eigen::MatrixXd H_; // Measurement matrix
    Eigen::MatrixXd Q_; // Process noise covariance matrix
    Eigen::MatrixXd R_; // Measurement noise covariance matrix

    // Kalman filter variables
    Eigen::VectorXd x_;     // State estimate
    Eigen::MatrixXd P_;     // State covariance
    Eigen::MatrixXd I_;     // Identity matrix
    bool is_initialized_;   // Flag indicating if the filter has been initialized
};

#endif // KALMAN_FILTER_H
