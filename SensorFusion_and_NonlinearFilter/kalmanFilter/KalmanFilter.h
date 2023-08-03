#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include<Eigen/Dense>
class KalmanFilter{
public:
    KalmanFilter(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
                 const Eigen::MatrixXd& H, const Eigen::MatrixXd& Q, 
                 const Eigen::MatrixXd& R);
    void init(const Eigen::VectorXd& initial_state, 
                const Eigen::MatrixXd& initial_state_covariance);


    // Perform the prediction step of the Kalman filter
    void predict(const Eigen::VectorXd& control_input);

    // Perform the correction step of the Kalman filter
    void correct(const Eigen::VectorXd& measurement);

    // Get the current state estimate
    Eigen::VectorXd getState() const;
private:
    Eigen::MatrixXd A_;
    Eigen::MatrixXd B_;
    Eigen::MatrixXd H_;
    Eigen::MatrixXd Q_;
    Eigen::MatrixXd R_;    

    Eigen::MatrixXd x_;
    Eigen::MatrixXd P_;
    Eigen::MatrixXd I_; 

    bool is_initialized_;
};

#endif;