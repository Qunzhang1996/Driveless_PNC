#include "path_planning.h"
// Define the dimensions of the map
extern const int mapWidth;
extern const int mapHeight;

std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
std::vector<PathNode> shortestPath;

int dijkstra(int startX, int startY, int targetX, int targetY, std::vector<std::vector<int>>& rasterMap) {
    const int inf = 1e9;
    std::vector<std::vector<int>> distance(rasterMap.size(), std::vector<int>(rasterMap[0].size(), inf));
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<std::vector<PathNode>> predecessor(rasterMap.size(), std::vector<PathNode>(rasterMap[0].size(), {-1, -1}));

    distance[startY][startX] = 0;
    pq.push(Node(startX, startY, 0));

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (node.x == targetX && node.y == targetY) {
            shortestPath.clear();
            for (PathNode n = predecessor[node.y][node.x]; n.x != -1; n = predecessor[n.y][n.x]) {
                shortestPath.push_back(n);
            }
            std::reverse(shortestPath.begin(), shortestPath.end());
            return distance[targetY][targetX];
        }

        for (const auto& dir : directions) {
            int newX = node.x + dir.first;
            int newY = node.y + dir.second;
            int newDist = node.distance + 1;

            if (newX >= 0 && newX < rasterMap[0].size() && newY >= 0 && newY < rasterMap.size() && rasterMap[newY][newX] == 0 && newDist < distance[newY][newX]) {
                distance[newY][newX] = newDist;
                predecessor[newY][newX] = {node.x, node.y};
                pq.push(Node(newX, newY, newDist));
            }
        }
    }

    // Target is not reachable
    return -1;
}
