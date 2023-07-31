#include "map_generation.h"

const int mapWidth = 150;
const int mapHeight = 150;

void generateMap(std::vector<std::vector<int>>& rasterMap) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0); // Generates a real number between 0.0 and 1.0

    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            rasterMap[i][j] = dis(gen) < 0.05 ? 1 : 0;  // 1% chance of obstacle
        }
    }

    // Ensure the start and end points are not obstacles
    rasterMap[0][0] = 0;
    rasterMap[mapHeight-1][mapWidth-1] = 0;
}
