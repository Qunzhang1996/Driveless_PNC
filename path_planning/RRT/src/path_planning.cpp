#include "path_planning.h"
#include <random>

RRT::RRT(Point start, Point targetPoint, const std::vector<std::vector<int>>& map) 
    : map(map) {
    startNode = new Node(start);
    target = new Node(targetPoint);
    nodes.push_back(startNode); // add the start point as the first node
}


RRT::~RRT() {
    for (auto node : nodes)
        if(node != startNode && node != target)
            delete node;
}


void RRT::buildRRT() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(5, map.size() - 1);
    std::uniform_int_distribution<> disY(5, map[0].size() - 1); // Assumes all rows have the same number of columns

    for (int i = 0; i < 1000; ++i) {
        int x = disX(gen);
        int y = disY(gen);
        if (map[x][y] != 1) {
            Node* nearest = nullptr;
            double minDist = std::numeric_limits<double>::max();
            for (auto node : nodes) {
                double dist = node->point.distance(Point(x, y));
                if (dist < minDist) {
                    minDist = dist;
                    nearest = node;
                }
            }
            if (nearest) {
                Node* newNode = new Node(Point(x, y), nearest);
                nodes.push_back(newNode);
            }
        }
    }
}


std::vector<Node*> RRT::getPath() {
    std::vector<Node*> path;
    Node* current = nodes.back();
    while (current) {
        path.push_back(current);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}
