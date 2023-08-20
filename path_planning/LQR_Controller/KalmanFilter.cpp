#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
                           const Eigen::MatrixXd& H, const Eigen::MatrixXd& Q,
                           const Eigen::MatrixXd& R, const Eigen::VectorXd& x0,
                           const Eigen::MatrixXd& P0)
    : A(A), B(B), H(H), Q(Q), R(R), x(x0), P(P0) {}

void KalmanFilter::predict(const Eigen::VectorXd& u) {
    x = A * x + B * u;
    P = A * P * A.transpose() + Q;
}

void KalmanFilter::update(const Eigen::VectorXd& z) {
    Eigen::VectorXd y = z - H * x;
    Eigen::MatrixXd S = H * P * H.transpose() + R;
    K = P * H.transpose() * S.inverse();
    x = x + K * y;
    P = (Eigen::MatrixXd::Identity(x.size(), x.size()) - K * H) * P;
}

Eigen::VectorXd KalmanFilter::state() const {
    return x;
}