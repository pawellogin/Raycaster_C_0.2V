#include "./include/MiniMap.h"
#include "./config/miniMapConfig.h"

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
    

    DrawCircleV(player.position,0.3*MINIMAP_SCALE,RED);

    Vector2 lineEnd = {player.position.x + MINIMAP_SCALE * player.direction.x, player.position.y + MINIMAP_SCALE * player.direction.y,};

    DrawLineEx(player.position,lineEnd,2,GREEN);

}
