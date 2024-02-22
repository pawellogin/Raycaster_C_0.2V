#ifndef TILETODRAW_H
#define TILETODRAW_H

#include "raylib.h"
#include "Map.h"

typedef enum Side{
    VERTICAL = 0,
    HORIZONTAL = 1
}Side;

typedef struct TileToDraw {
    TileName name;
    Color color;
    float height;
    bool isTransparent;
    float rayLength;
    Side side;
    Vector2 cords; 

}TileToDraw;

TileToDraw createTileToDraw(
    TileName name,
    Color color,
    float height,
    bool isTransparent,
    float rayLength,
    Side side,
    Vector2 cords
);

#endif