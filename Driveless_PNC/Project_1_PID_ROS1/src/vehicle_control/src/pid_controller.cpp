#include "pid_controller.h"

namespace shenlan {
namespace control {

PIDController::PIDController(const double kp, const double ki,
                             const double kd) {
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;
  previous_error_ = 0.0;
  previous_output_ = 0.0;
  integral_ = 0.0;
  first_hit_ = true;
}

// /**to-do**/ 计算 PID 输出，实现PID控制
double PIDController::Control(const double error, const double dt) {
  double P_out=kp_*error;
  double I_out=ki_*integral_;
  double derivative = (error - previous_error_) / dt;
  double D_out = kd_* derivative;
  double output = P_out + I_out + D_out;
  previous_error_ = error;
return output;
}

// /**to-do**/ 重置PID参数
void PIDController::Reset() {
    previous_error_ = 0.0;   // Reset the previous error
    previous_output_ = 0.0;  // Reset the previous output (even if it's not being used in the Control method, good to reset)
    integral_ = 0.0;         // Reset the integral term
    first_hit_ = true;       // Reset the first hit flag
}

}  // namespace control
}  // namespace shenlan
