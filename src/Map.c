#include <stdlib.h>
#include <stdio.h>
#include "./include/Map.h"
#include "./config/mapConfig.h"

Map* mapCreateEmptyWithBarriers(){

    Map* newMap = (Map*)malloc(sizeof(Map));

    newMap->height = MAP_HEIGHT;
    newMap->width = MAP_WIDTH;

    bool isTileAtTheBorder = false;

    newMap->mapGrid = (Tile**)malloc(MAP_HEIGHT * sizeof(Tile*));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        newMap->mapGrid[i] = (Tile*)malloc(MAP_WIDTH * sizeof(Tile));
    }

     for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if((i == 0 || i == MAP_HEIGHT-1) || (j == 0 || j == MAP_WIDTH -1)) isTileAtTheBorder = true;
            else isTileAtTheBorder = false;

            if(isTileAtTheBorder){
                newMap->mapGrid[i][j] = tileCreateBarrierTile();
            }else{
                newMap->mapGrid[i][j] = tileCreateEmptyTile();
            }
        }
    }

    return newMap;
}

Tile mapGetTile(Map map, Vector2 position) {
    Vector2 gridPos = {
        position.x,
        position.y 
    };

    int x = (int)gridPos.x;
    int y = (int)gridPos.y;

    if (x >= 0 && x < map.width && y >= 0 && y < map.height) {
        return map.mapGrid[x][y]; 
    } else {
        return tileCreateErrorTile();
    }
}

bool mapIsTilePassThrought(Map map, Vector2 position){
    Vector2 gridPos = {
        position.x,
        position.y 
    };

    Tile tile = tileCreateErrorTile();

    int x = (int)gridPos.x;
    int y = (int)gridPos.y;


    if (x >= 0 && x < map.width && y >= 0 && y < map.height) {
        tile = map.mapGrid[x][y];
    } else {
        return -1;
    }

    return tile.isWalkThrought;
}

void mapFreeMapGrid(Map* map) {
    for (int i = 0; i < map->height; i++) {
        free(map->mapGrid[i]);
    }
    free(map->mapGrid);
}

void mapCreateTestRoom(Map* map){
    if(map->height < 8 && map->width < 8){
        return;
    }

    int startRow = (map->height - 5) / 2;
    int startCol = (map->width - 5) / 2;

    for (int i = startRow; i < startRow + 5; i++) {
        for (int j = startCol; j < startCol + 5; j++) {
            if (i == startRow || i == startRow + 4 || j == startCol || j == startCol + 4) {
                map->mapGrid[i][j] = tileCreateStoneTile();
            } else {
                map->mapGrid[i][j] = tileCreateEmptyTile();
            }
        }
    }

    map->mapGrid[startRow + 2][startCol] = tileCreateEmptyTile();
    map->mapGrid[startRow][startCol + 2] = tileCreateGlassTile();
    map->mapGrid[startRow + 4][startCol + 2] = tileCreateGlassTile();
    

    
}

    
