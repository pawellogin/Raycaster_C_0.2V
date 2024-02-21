#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include "raylib.h"

typedef struct Map{
    int height;
    int width;
    Tile** mapGrid;
}Map;
 
    Map* mapCreateEmptyWithBarriers();
    Tile mapGetTile(Map map, Vector2 position);
    bool mapIsTilePassThrought(Map map, Vector2 position);

#endif