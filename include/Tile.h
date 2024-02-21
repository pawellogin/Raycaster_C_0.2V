#pragma once 
#include "raylib.h"

typedef enum TileName{
    EMPTY,
    STONE,
    GLASS,
    BARRIER
}TileName;

typedef struct Tile {
    TileName name;
    Color color;
    float height;
    bool isPassThrought;
}Tile;
