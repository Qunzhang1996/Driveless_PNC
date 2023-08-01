#ifndef PATH_SMOOTHING_H
#define PATH_SMOOTHING_H
#include<vector>
#include "path_planning.h"

// Smooth the path using Bezier curve interpolation with obstacle avoidance
std::vector<Point> bezierCurveInterpolation(const std::vector<Point>& points);

#endif // PATH_SMOOTHING_H
