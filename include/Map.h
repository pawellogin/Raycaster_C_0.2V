#pragma once
#include "Tile.h"

typedef struct Map{
    int MAP_HEIGHT;
    int MAP_WIDTH;
    Tile** mapGrid;
}Map;
 
    void mapInitialize(Map map, int mapHeight, int mapWidth);
    TileName getTileType(int width, int height);