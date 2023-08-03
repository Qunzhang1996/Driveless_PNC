#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include<cmath>

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    double distance(Point p)
    {
        return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
    }
};

struct Node {
    Point point;
    Node* parent; // change from std::shared_ptr<Node> to Node*

    Node(Point point, Node* parent = nullptr) : point(point), parent(parent) {} // change from std::shared_ptr<Node> to Node*
};

class RRT {
public:
    RRT(Point start, Point target, const std::vector<std::vector<int>>& map);
    ~RRT();
    void buildRRT();
    std::vector<Node*> getPath();
    
private:
    Node* startNode;
    Node* target;
    std::vector<Node*> nodes;
    std::vector<std::vector<int>> map;
};

