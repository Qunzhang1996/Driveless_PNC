#include <iostream>
#include <algorithm>

class PID_Controller {
private:
    double kp;
    double ki;
    double kd;
    
    double integral;
    double prev_error;
    
public:
    PID_Controller(double kp_, double ki_, double kd_)
        : kp(kp_), ki(ki_), kd(kd_), integral(0), prev_error(0) {}

    double calculate(double setpoint, double actual_value) {
        double error = setpoint - actual_value;

        integral += error;
        double derivative = error - prev_error;

        double output = kp * error + ki * integral + kd * derivative;

        prev_error = error;

        return output;
    }
};

class ACC {
private:
    PID_Controller pid;
    double D_set;             // Desired distance to the preceding vehicle
    double D_safe;            // Safe distance to the preceding vehicle
    double v_set;             // Set speed for the ego vehicle
    
public:
    ACC(double kp, double ki, double kd, double D_set_, double D_safe_, double v_set_)
        : pid(kp, ki, kd), D_set(D_set_), D_safe(D_safe_), v_set(v_set_) {}

    double adjustSpeed(double D_rel, double v_ego) {
        double control_input;
        
        if (D_rel < D_safe) {
            control_input = pid.calculate(D_set, D_rel);
        } else {
            control_input = pid.calculate(v_set, v_ego);
        }

        // Adjust ego vehicle speed
        v_ego += control_input;

        // Ensure speed is within acceptable limits
        v_ego = std::clamp(v_ego, 0.0, 120.0);  // Assuming 0 to 120 km/h

        return v_ego;
    }
};

int main() {
    ACC acc(0.1, 0.01, 0.02, 20.0, 25.0, 100.0);  // Example parameters

    double distance_to_preceding_vehicle = 30.0; // Example starting distance
    double v_ego = 90.0;  // Example starting ego vehicle speed

    for (int i = 0; i < 10; ++i) {  // Run for 10 iterations as an example
        v_ego = acc.adjustSpeed(distance_to_preceding_vehicle, v_ego);
        std::cout << "Current ego vehicle speed: " << v_ego << " km/h" << std::endl;

        // For simplicity, let's assume the distance decreases by 2 each iteration
        distance_to_preceding_vehicle -= 2.0;
    }

    return 0;
}
