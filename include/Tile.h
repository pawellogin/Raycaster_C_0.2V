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
    bool isWalkThrought;
    bool isTransparent;
}Tile;

Tile createTile(
    TileName name,
    Color color,
    float height,
    bool isWalkThrought,
    bool isTransparent
    );
Tile tileCreateEmptyTile();
Tile tileCreateBarrierTile();
Tile tileCreateErrorTile();
Tile tileCreateStoneTile();
Tile tileCreateGlassTile();
const char* tileNameToString(TileName tileName);

#endif
