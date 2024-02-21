#ifndef TILE_H
#define TILE_H

#include "raylib.h"

typedef enum TileName{
    EMPTY,
    STONE,
    GLASS,
    BARRIER,
    ERROR
}TileName;

typedef struct Tile {
    TileName name;
    Color color;
    float height;
    bool isPassThrought;
}Tile;

Tile createEmptyTile();
Tile createBarrierTile();
Tile createErrorTile();

#endif
