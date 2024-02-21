#include "./include/Tile.h"

Tile createEmptyTile(){
    return(Tile){
        .color = (Color){0,0,0,0},
        .height = 0.0f,
        .isPassThrought = true,
        .name = EMPTY
    };
}

Tile createErrorTile(){
    return(Tile){
        .color = (Color){255,0,220,0},
        .height = 100.0f,
        .isPassThrought = false,
        .name = ERROR
    };
}

Tile createBarrierTile(){
    return(Tile){
        .color = (Color){0,0,0,0},
        .height = 1.0f,
        .isPassThrought = false,
        .name = BARRIER
    }; 
}

