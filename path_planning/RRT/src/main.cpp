#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "map_generation.h"
#include "path_planning.h"


void renderMap(const std::vector<std::vector<int>>& rasterMap, const std::vector<Node*>& path) {
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
    for (const auto& node : path) {
        SDL_Rect rect = {node->point.x * pixelSize, node->point.y * pixelSize, pixelSize, pixelSize};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(100); // delay to show each step
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(50000); // Wait for 5 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


int main() {
    std::vector<std::vector<int>> rasterMap(mapHeight, std::vector<int>(mapWidth, 0));
    generateMap(rasterMap);

    int startX = 0;
    int startY = 0;
    int targetX = mapWidth-20; // coordinates should be within the map bounds
    int targetY = mapHeight-80;

    Point start(startX, startY);
    Point target(targetX, targetY);

    // Initialize RRT and build the tree
    RRT rrt(start, target, rasterMap);
    rrt.buildRRT();

    // Retrieve the path from the RRT
    std::vector<Node*> path = rrt.getPath();

    if (path.empty()) {
        std::cout << "Target is not reachable from the starting point." << std::endl;
    } else {
        std::cout << "Shortest distance to the target: " << path.size() - 1 << std::endl;
    }

    // Render the map with the path
    renderMap(rasterMap, path);

    return 0;
}
