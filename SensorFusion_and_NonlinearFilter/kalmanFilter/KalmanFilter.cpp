#include "kalmanFilter/KalmanFilter.h""

KalmanFilter::KalmanFilter(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
                 const Eigen::MatrixXd& H, const Eigen::MatrixXd& Q, 
                 const Eigen::MatrixXd& R):A_(A),B_(B), H_(H), Q_(Q), R_(R), is_initialized_(false){
                I_=Eigen::MatrixXd::Identity(A_.rows(),A_.cols());
}
void KalmanFilter::init(const Eigen::VectorXd& initial_state, const Eigen::MatrixXd& initial_state_covariance){
    x_=initial_state;
    P_=initial_state_covariance;
    is_initialized_=true;
};
void KalmanFilter::predict(const Eigen::VectorXd& control_input){
    x_=A_*x_+B_*control_input;
    P_=A_*P_*A_.transpose()+Q_;
};

    // Perform the correction step of the Kalman filter
void KalmanFilter::correct(const Eigen::VectorXd& measurement){
    Eigen::MatrixXd S=H_*P_*H_.transpose()+R_;
    Eigen::MatrixXd K=P_*H_.transpose()*S.inverse();

    x_=x_+K*(measurement - H_*x_);
    P_=(I_-K*H_)*P_;


};

    // Get the current state estimate
Eigen::VectorXd KalmanFilter::getState() const{
    return x_;

};