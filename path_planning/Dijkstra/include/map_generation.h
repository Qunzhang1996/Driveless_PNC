#ifndef MAP_GENERATION_H
#define MAP_GENERATION_H

#include <vector>
#include <random>

extern const int mapWidth;
extern const int mapHeight;

void generateMap(std::vector<std::vector<int>>& rasterMap);

#endif
