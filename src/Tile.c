#include "./include/Tile.h"

Tile createTile(
    TileName name,
    Color color,
    float height,
    bool isWalkThrought,
    bool isTransparent
    ){
    return(Tile){
        .name = name,
        .color = color,
        .height = height,
        .isWalkThrought = isWalkThrought,
        .isTransparent = isTransparent
    };
};

Tile TileCreateEmptyTile(){
    return createTile(
        EMPTY,
        (Color){0,0,0,0},
        0.0f,
        true,
        true
    );
}

Tile TileCreateErrorTile(){
    return createTile(
      ERROR,
      (Color){255,0,220,0},
      100.0f,
      false,
      false  
    );
}

Tile TileCreateBarrierTile(){
    return createTile(
        BARRIER,
        (Color){0,0,0,0},
        1.0f,
        false,
        false
    );
}

Tile TileCreateStoneTile(){
    return createTile(
        STONE,
        GRAY,
        1.0f,
        false,
        false
    );
}

