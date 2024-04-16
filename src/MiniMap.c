#include "./include/MiniMap.h"
#include "./config/miniMapConfig.h"
#include "./include/Raycaster.h"

Vector2 miniMapGiveConvertedCords(Vector2 cords){
    cords.x = cords.x * MINIMAP_SCALE;
    cords.x += MINIMAP_OFFSET_X;
    
    cords.y = cords.y * MINIMAP_SCALE;
    cords.y += MINIMAP_OFFSET_Y;

    return cords;
}


void miniMapDrawMiniMap(Player player,Map map){

    Color tileColor = BLANK;

    for(int i = 0; i < map.height; i++) {
        for(int j = 0; j< map.width;j++){
            switch(map.mapGrid[i][j].name){
                case EMPTY:
                tileColor = RAYWHITE;
                break;
                
                default:
                tileColor = GRAY;
            }
            DrawRectangle(i*MINIMAP_SCALE + MINIMAP_OFFSET_X,j*MINIMAP_SCALE,MINIMAP_SCALE-1,MINIMAP_SCALE-1,tileColor);          
        }
    }

    player.position.x = player.position.x * MINIMAP_SCALE;
    player.position.x += MINIMAP_OFFSET_X;
    
    player.position.y = player.position.y * MINIMAP_SCALE;
    player.position.y += MINIMAP_OFFSET_Y;

    

    DrawCircleV(player.position,0.3*MINIMAP_SCALE,RED);

    Vector2 lineEnd = {player.position.x + MINIMAP_SCALE * player.direction.x, player.position.y + MINIMAP_SCALE * player.direction.y,};

    DrawLineEx(player.position,lineEnd,2,GREEN);

}

void miniMapRaycastSingleRay(Player player, Map map){
    size_t arraySize = 0;
    TileToDraw* tileArray = NULL;
    tileArray = raycasterCastRay(player,map, &arraySize);


    if(tileArray != NULL){
        Vector2 endCords = {
            player.position.x + player.direction.x * tileArray[0].rayLength,
            player.position.y + player.direction.y * tileArray[0].rayLength,
        };

        endCords = miniMapGiveConvertedCords(endCords);

        player.position = miniMapGiveConvertedCords(player.position);
        DrawLineV(player.position,endCords,RED);
        free(tileArray);
    }
}
