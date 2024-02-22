#include "./include/TileToDraw.h"

TileToDraw createTileToDraw(
    TileName name,
    Color color,
    float height,
    bool isTransparent,
    float rayLength,
    Side side,
    Vector2 cords
){
    return(TileToDraw){
        .name = name,
        .color = color,
        .height = height,
        .isTransparent = isTransparent,
        .rayLength = rayLength,
        .side = side,
        .cords = cords
    };

}