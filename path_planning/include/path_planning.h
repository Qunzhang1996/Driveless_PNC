#ifndef PATH_PLANNING_H
#define PATH_PLANNING_H

#include <vector>
#include <queue>
#include <algorithm>

// Define nodes for path and the shortest path
struct Node {
    int x, y;
    int distance;
    Node(int _x, int _y, int _distance) : x(_x), y(_y), distance(_distance) {}
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

struct PathNode {
    int x, y;
    PathNode(int _x, int _y) : x(_x), y(_y) {}
};

// Directions for neighbors in the grid
extern std::vector<std::pair<int, int>> directions;
extern std::vector<PathNode> shortestPath;

int dijkstra(int startX, int startY, int targetX, int targetY, std::vector<std::vector<int>>& rasterMap);

#endif
