#ifndef PATH_PLANNING_H
#define PATH_PLANNING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>


struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    double distance(Point p)
    {
        return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
    }
};

struct Node
{
    Point point;
    double f, g, h;
    std::shared_ptr<Node> parent;
    Node(Point point, double f, std::shared_ptr<Node> parent, double g, double h) : point(point), f(f), parent(parent), g(g), h(h) {}
};

struct NodeCompare
{
    bool operator()(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2)
    {
        return n1->f < n2->f;
    }
};

std::vector<Point> AStar(std::vector<std::vector<int>>& raster_map, Point& start, Point& target);

#endif // PATH_PLANNING_H
