#include<iostream>
#include<Eigen/Dense>
#include <random>
using namespace std;
/*
A=[0 1 0 0;0 0 0 0;0 0 0 1;0 0 0 0];
B=[0 0 ;1 0;0 0;0 1];
TS=0.1;
sys_continuous = ss(A, B, [], []);
sys_discrete = c2d(sys_continuous, TS);
Ad = sys_discrete.A

    1.0000    0.1000         0         0
         0    1.0000         0         0
         0         0    1.0000    0.1000
         0         0         0    1.0000
Bd = sys_discrete.B
    0.0050         0
    0.1000         0
         0    0.0050
         0    0.1000
Q=eye(4);Q(1,1)=10;Q(3,3)=10
R=eye(2)
lqr gain
    2.7623    2.5075    0.0000    0.0000
    0.0000    0.0000    2.7623    2.5075
*/
class Vehicle {
private:
    Eigen::MatrixXd Ad;
    Eigen::MatrixXd Bd;
    Eigen::Matrix4d Cd=Eigen::Matrix4d::Identity();
    double mass;
    double generateGaussianNoise(double standard_deviation) const {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> d{0, standard_deviation};
        return d(gen);
    }

    Eigen::Vector4d getGaussianNoiseVector() const {
        Eigen::Vector4d noise;
        noise << generateGaussianNoise(1),  // Noise for position in X
                 generateGaussianNoise(0.5), // Noise for velocity in X
                 generateGaussianNoise(1),  // Noise for position in Y
                 generateGaussianNoise(0.5); // Noise for velocity in Y
        return noise;
    }

public:
    Eigen::Vector4d states;
    Eigen::Vector4d measurement;
    Vehicle(const Eigen::MatrixXd &Ad, const Eigen::MatrixXd &Bd, double mass) : 
    Ad(Ad), Bd(Bd), mass(mass) {
        states = Eigen::Vector4d::Zero();
    }

    void applyForce(Eigen::Vector2d &input) {
        measurement=Cd*states+getGaussianNoiseVector();
        states = Ad * states + Bd * input + getGaussianNoiseVector();
        
    }
    double getXPos() const { return measurement(0); }
    double getYPos() const { return measurement(2); }
    double getXVel() const { return measurement(1); }
    double getYVel() const { return measurement(3); }
};

Eigen::Vector2d LQR_controller(const Vehicle& vehicle, const Eigen::MatrixXd& K, double setPointX, double setPointY) 
{
    Eigen::Vector4d ref;
    ref << setPointX, 0, setPointY, 0;

    Eigen::Vector4d error = ref - vehicle.states;

    // Compute the control input using the LQR gain
    Eigen::Vector2d input = -K * error;

    return input;
}
int main()
{
    Eigen::MatrixXd Ad(4,4);  // Explicitly define the size to be safe
    Ad << 1.0,    0.1,   0.0,   0.0,
        0.0,    1.0,   0.0,   0.0,
        0.0,    0.0,   1.0,   0.1,
        0.0,    0.0,   0.0,   1.0; 


    Eigen::MatrixXd Bd(4,2);
    Bd<<0.0050,        0,
        0.1000,         0, 
            0,     0.0050,
            0,     0.1000;

    Eigen::MatrixXd K(2,4);
    K<<2.7623,    2.5075,    0,    0,
        0,    0,    2.7623,    2.5075;
    K=-K;
    Vehicle vehicle(Ad, Bd,1000);
    double setPointX = 90;
    double setPointY = 100;
    for (int time = 0; time < 100; time++) 
    {
        Eigen::Vector2d controlInput = LQR_controller(vehicle, K, setPointX, setPointY);
        vehicle.applyForce(controlInput);
        std::cout << "Time: " << time << ", X: " << vehicle.getXPos() << ", Y: " << vehicle.getYPos()
        << ", V_x: " << vehicle.getXVel() << ", V_y: " << vehicle.getYVel() << std::endl;
    }
    return 0;
}


