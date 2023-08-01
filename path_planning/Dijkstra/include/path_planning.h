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
    Point(int x, int y) : x(x), y(y) {}
    double distance(Point p)
    {
        return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
    }
};

struct Node
{
    Point point;
    double g;
    std::shared_ptr<Node> parent;
    Node(Point point, double g, std::shared_ptr<Node> parent) : point(point), g(g), parent(parent) {}
};

struct NodeCompare
{
    bool operator()(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2)
    {
        return n1->g < n2->g;
    }
};

std::vector<Point> dijkstra(std::vector<std::vector<int>>& raster_map, Point& start, Point& target);

#endif // PATH_PLANNING_H
