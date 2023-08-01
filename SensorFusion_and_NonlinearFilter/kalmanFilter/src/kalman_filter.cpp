#include "kalman_filter.h"

KalmanFilter::KalmanFilter(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
                           const Eigen::MatrixXd& H, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R)
    : A_(A), B_(B), H_(H), Q_(Q), R_(R), is_initialized_(false) {
    I_ = Eigen::MatrixXd::Identity(A_.rows(), A_.cols());
}

void KalmanFilter::init(const Eigen::VectorXd& initial_state, const Eigen::MatrixXd& initial_state_covariance) {
    x_ = initial_state;
    P_ = initial_state_covariance;
    is_initialized_ = true;
}

void KalmanFilter::predict(const Eigen::VectorXd& control_input) {
    // Prediction step: x(k|k-1) = A * x(k-1|k-1) + B * u(k)
    x_ = A_ * x_ + B_ * control_input;

    // Covariance update: P(k|k-1) = A * P(k-1|k-1) * A^T + Q
    P_ = A_ * P_ * A_.transpose() + Q_;
}

void KalmanFilter::correct(const Eigen::VectorXd& measurement) {
    // Kalman gain: K(k) = P(k|k-1) * H^T * (H * P(k|k-1) * H^T + R)^(-1)
    Eigen::MatrixXd S = H_ * P_ * H_.transpose() + R_;
    Eigen::MatrixXd K = P_ * H_.transpose() * S.inverse();

    // Correction step: x(k|k) = x(k|k-1) + K(k) * (z(k) - H * x(k|k-1))
    x_ = x_ + K * (measurement - H_ * x_);

    // Covariance update: P(k|k) = (I - K(k) * H) * P(k|k-1)
    P_ = (I_ - K * H_) * P_;
}

Eigen::VectorXd KalmanFilter::getState() const {
    return x_;
}
