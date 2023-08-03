#include"path_smoothing.h"
std::vector<Point> bezierCurveInterpolation(const std::vector<Point>& points) {
    std::vector<Point> smoothedPath;

    for (size_t i = 0; i < points.size() - 3; i += 3) {
        double t = 0.0;
        while (t <= 1.0) {
            int x = static_cast<int>((1 - t) * (1 - t) * (1 - t) * points[i].x + 3 * t * (1 - t) * (1 - t) * points[i + 1].x +
                                     3 * t * t * (1 - t) * points[i + 2].x + t * t * t * points[i + 3].x);

            int y = static_cast<int>((1 - t) * (1 - t) * (1 - t) * points[i].y + 3 * t * (1 - t) * (1 - t) * points[i + 1].y +
                                     3 * t * t * (1 - t) * points[i + 2].y + t * t * t * points[i + 3].y);

            smoothedPath.push_back({x, y});
            t += 0.05; // You can adjust this step value for smoother curves
        }
    }

    return smoothedPath;
}