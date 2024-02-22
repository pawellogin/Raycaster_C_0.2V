#include "./include/Raycaster.h"

TileToDraw* raycasterCastRay(Player player, Map map, size_t* tileArraySize){

    TileToDraw* tileArray = (TileToDraw*)malloc(TILE_BUFFER_SIZE * sizeof(TileToDraw));
    size_t tileArrayId = 0;

    Vector2 rayUnitStepSize = {
        sqrt(1+(player.direction.y / player.direction.x) * (player.direction.y / player.direction.x)),
        sqrt(1+(player.direction.x / player.direction.y) * (player.direction.x / player.direction.y))
        };

    Vector2 mapPositionCheck  = {(int)player.position.x,(int)player.position.y};

    Vector2 raylength = {0.0f,0.0f};

    Vector2 step = {0.0f,0.0f};

    if(player.direction.x < 0){
        step.x = -1;
        raylength.x = (player.position.x - (float)(mapPositionCheck.x)) * rayUnitStepSize.x;
    }
    else{
        step.x = 1;
        raylength.x = ((float)(mapPositionCheck.x + 1) - player.position.x) * rayUnitStepSize.x;
    }
    if(player.direction.y < 0){
        step.y = -1;
        raylength.y = (player.position.y - (float)(mapPositionCheck.y)) * rayUnitStepSize.y;
    }
    else{
        step.y = 1;
        raylength.y = ((float)(mapPositionCheck.y + 1) - player.position.y) * rayUnitStepSize.y;
    }

    bool tileFound = false;
    float maxDistance = 20.0f;
    float distance = 0.0f;
    Tile tileToCheck;

    int axis = 0;

    while(!tileFound && distance < maxDistance){


        if(raylength.x < raylength.y){
            mapPositionCheck.x +=step.x;
            distance = raylength.x;
            raylength.x += rayUnitStepSize.x;
            axis = 0;
        }
        else{
            mapPositionCheck.y += step.y;
            distance = raylength.y;
            raylength.y += rayUnitStepSize.y; 
            axis = 1;            
        }

        tileToCheck = mapGetTile(map, mapPositionCheck);

        if(tileToCheck.isTransparent && tileToCheck.name != EMPTY){
            tileArray[tileArrayId].name = tileToCheck.name;
            tileArray[tileArrayId].color = tileToCheck.color;
            tileArray[tileArrayId].height = tileToCheck.height;
            tileArray[tileArrayId].isTransparent = tileToCheck.isTransparent;
            tileArray[tileArrayId].rayLength = distance;
            tileArray[tileArrayId].side = (Side)axis;
            tileArray[tileArrayId].cords.x = (int)(mapPositionCheck.x);
            tileArray[tileArrayId].cords.y = (int)(mapPositionCheck.y);


            tileArrayId++;  

            *tileArraySize = tileArrayId; 
        }else if(!tileToCheck.isTransparent && tileToCheck.name != EMPTY){
            tileFound = true;
            
            tileArray[tileArrayId].name = tileToCheck.name;
            tileArray[tileArrayId].color = tileToCheck.color;
            tileArray[tileArrayId].height = tileToCheck.height;
            tileArray[tileArrayId].isTransparent = tileToCheck.isTransparent;
            tileArray[tileArrayId].rayLength = distance;
            tileArray[tileArrayId].side = (Side)axis;
            tileArray[tileArrayId].cords.x = (int)(mapPositionCheck.x);
            tileArray[tileArrayId].cords.y = (int)(mapPositionCheck.y);


            tileArrayId++;            

            *tileArraySize = tileArrayId;
            return tileArray;
        }
    } 
     return NULL;
}
