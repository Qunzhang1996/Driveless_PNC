#include "stanley_control.h"

#include <algorithm>
#include <iomanip>
#include <utility>
#include <vector>

#include "Eigen/LU"
#include <math.h>

using namespace std;

namespace shenlan {
namespace control {

double atan2_to_PI(const double atan2) {
  return atan2 * M_PI / 180;
}

double PointDistanceSquare(const TrajectoryPoint &point, const double x,
                           const double y) {
  const double dx = point.x - x;
  const double dy = point.y - y;
  return dx * dx + dy * dy;
}

void StanleyController::LoadControlConf() {
  k_y_ = 0.5;
}

// /** to-do **/ 计算需要的控制命令, 实现对应的stanley模型,并将获得的控制命令传递给汽车
// 提示，在该函数中你需要调用计算误差 ComputeLateralErrors
void StanleyController::ComputeControlCmd(
    const VehicleState &vehicle_state,
    const TrajectoryData &planning_published_trajectory, ControlCmd &cmd) {
    double e_theta, e_y;
    trajectory_points_ = planning_published_trajectory.trajectory_points;
    ComputeLateralErrors(vehicle_state.x, vehicle_state.y, vehicle_state.heading, 
                                            e_y, e_theta);
    if(vehicle_state.velocity == 0) {
        cmd.steer_target = 0;  // Handle the stationary case to avoid division by zero.
    } else {
        cmd.steer_target = e_theta + atan2(k_y_ * e_y, vehicle_state.velocity+EPSILON);
    }

}

// /** to-do **/ 计算需要的误差，包括横向误差，纵向误差
void StanleyController::ComputeLateralErrors(const double x, const double y,
                                             const double theta, double &e_y,
                                             double &e_theta) {
    TrajectoryPoint target_point_=QueryNearestPointByPosition(x,y);
    double dx=x-target_point_.x;
    double dy=y-target_point_.y;
    e_y=-dx*sin(target_point_.heading)+dy*cos(target_point_.heading);
    e_theta=theta-theta_ref_;
    while(e_theta>M_PI) e_theta-=2.0*M_PI;
    while(e_theta<-M_PI) e_theta+=2.0*M_PI;
}

TrajectoryPoint StanleyController::QueryNearestPointByPosition(const double x,
                                                               const double y) {
  double d_min = PointDistanceSquare(trajectory_points_.front(), x, y);
  size_t index_min = 0;

  for (size_t i = 1; i < trajectory_points_.size(); ++i) {
    double d_temp = PointDistanceSquare(trajectory_points_[i], x, y);
    if (d_temp < d_min) {
      d_min = d_temp;
      index_min = i;
    }
  }
  // cout << " index_min: " << index_min << endl;
  //cout << "tarjectory.heading: " << trajectory_points_[index_min].heading << endl;
  theta_ref_ = trajectory_points_[index_min].heading;

  return trajectory_points_[index_min];
}

}  // namespace control
}  // namespace shenlan
