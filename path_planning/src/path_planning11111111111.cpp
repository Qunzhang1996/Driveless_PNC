#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <algorithm>
#include <SDL2/SDL.h>

// Define the dimensions of the map
const int mapWidth = 110;
const int mapHeight = 110;

// Define the raster map as a 2D vector
std::vector<std::vector<int>> rasterMap(mapHeight, std::vector<int>(mapWidth, 0));

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

std::vector<PathNode> shortestPath;

// Directions for neighbors in the grid
std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void generateMap() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0); // Generates a real number between 0.0 and 1.0

    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            rasterMap[i][j] = dis(gen) < 0.01 ? 1 : 0;  // 1% chance of obstacle
        }
    }

    // Ensure the start and end points are not obstacles
    rasterMap[0][0] = 0;
    rasterMap[mapHeight-1][mapWidth-1] = 0;
}


int dijkstra(int startX, int startY, int targetX, int targetY) {
    const int inf = 1e9;
    std::vector<std::vector<int>> distance(mapHeight, std::vector<int>(mapWidth, inf));
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<std::vector<PathNode>> predecessor(mapHeight, std::vector<PathNode>(mapWidth, {-1, -1}));

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

            if (newX >= 0 && newX < mapWidth && newY >= 0 && newY < mapHeight && rasterMap[newY][newX] == 0 && newDist < distance[newY][newX]) {
                distance[newY][newX] = newDist;
                predecessor[newY][newX] = {node.x, node.y};
                pq.push(Node(newX, newY, newDist));
            }
        }
    }

    // Target is not reachable
    return -1;
}

void renderMap() {
    const int pixelSize = 4;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(mapWidth * pixelSize, mapHeight * pixelSize, 0, &window, &renderer);

    // Clear the current rendering target with the drawing color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Set color for obstacles
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            if (rasterMap[i][j] == 1) {
                SDL_Rect rect = {j * pixelSize, i * pixelSize, pixelSize, pixelSize};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // Set color for shortest path
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (const auto& node : shortestPath) {
        SDL_Rect rect = {node.x * pixelSize, node.y * pixelSize, pixelSize, pixelSize};
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(50000); // Wait for 5 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    generateMap();
    int startX = 0;
    int startY = 0;
    int targetX = 100; // coordinates should be within the map bounds
    int targetY = 100;

    // Call Dijkstra's algorithm and get the shortest distance to the target
    int shortestDistance = dijkstra(startX, startY, targetX, targetY);

    if (shortestDistance == -1) {
        std::cout << "Target is not reachable from the starting point." << std::endl;
    } else {
        std::cout << "Shortest distance to the target: " << shortestDistance << std::endl;
    }

    // Render the map with the path
    renderMap();

    return 0;
}
