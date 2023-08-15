#ifndef RDP_H
#define RDP_H

#include <vector>

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    double distance(Point p) const {
        return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
    }
};

std::vector<Point> rdp(const std::vector<Point>& points, double epsilon);

#endif // RDP_H
