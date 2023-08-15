#include "rdp.h"
#include <cmath>

double pointToLineDist(const Point &p, const Point &a, const Point &b) {
    double A = b.y - a.y;
    double B = a.x - b.x;
    double C = b.x * a.y - a.x * b.y;
    return std::abs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
}

std::vector<Point> rdp(const std::vector<Point>& points, double epsilon) {
    if (points.size() < 3) {
        return points;
    }

    Point beginPoint = points.front();
    Point endPoint = points.back();

    double maxDist = 0;
    size_t index = 0;

    for (size_t i = 1; i < points.size() - 1; ++i) {
        double d = pointToLineDist(points[i], beginPoint, endPoint);
        if (d > maxDist) {
            index = i;
            maxDist = d;
        }
    }

    std::vector<Point> simplified;

    if (maxDist > epsilon) {
        std::vector<Point> firstSegment(points.begin(), points.begin() + index + 1);
        std::vector<Point> secondSegment(points.begin() + index, points.end());

        std::vector<Point> rdpFirst = rdp(firstSegment, epsilon);
        std::vector<Point> rdpSecond = rdp(secondSegment, epsilon);

        simplified.insert(simplified.end(), rdpFirst.begin(), rdpFirst.end() - 1);
        simplified.insert(simplified.end(), rdpSecond.begin(), rdpSecond.end());
    } else {
        simplified.push_back(beginPoint);
        simplified.push_back(endPoint);
    }

    return simplified;
}
