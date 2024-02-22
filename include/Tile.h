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
Tile TileCreateEmptyTile();
Tile TileCreateBarrierTile();
Tile TileCreateErrorTile();
Tile TileCreateStoneTile();

#endif
