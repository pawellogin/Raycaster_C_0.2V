#include <stdlib.h>
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
                newMap->mapGrid[i][j] = createBarrierTile();
            }else{
                newMap->mapGrid[i][j] = createEmptyTile();
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
        return createErrorTile();
    }
}

bool mapIsTilePassThrought(Map map, Vector2 position){
    Vector2 gridPos = {
        position.x,
        position.y 
    };

    Tile tile = createErrorTile();

    int x = (int)gridPos.x;
    int y = (int)gridPos.y;


    if (x >= 0 && x < map.width && y >= 0 && y < map.height) {
        tile = map.mapGrid[x][y];
    } else {
        return -1;
    }

    return tile.isPassThrought;
}
    
