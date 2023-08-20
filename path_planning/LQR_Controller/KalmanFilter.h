#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include <Eigen/Dense>

class KalmanFilter {
private:
    Eigen::MatrixXd A, B, H, Q, R, P, K;
    Eigen::VectorXd x; // state vector

public:
    // Constructor
    KalmanFilter(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
                 const Eigen::MatrixXd& H, const Eigen::MatrixXd& Q,
                 const Eigen::MatrixXd& R, const Eigen::VectorXd& x0,
                 const Eigen::MatrixXd& P0);

    // Predict step
    void predict(const Eigen::VectorXd& u);

    // Update step
    void update(const Eigen::VectorXd& z);

    // Return the current state estimate
    Eigen::VectorXd state() const;
};

#endif