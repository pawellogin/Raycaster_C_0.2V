#include "./include/Player.h"
#include "./include/Map.h"

Player playerCreate(){
    return(Player){
        .position.x = 15.5f,
        .position.y = 7.0f,
        .direction.x = 0,
        .direction.x = 0,
        .angle = 90 * DEG2RAD,
        .movementSpeed = PLAYER_MOVEMENT_SPEED,
        .FOV = PLAYER_FOV
    };
}

void playerMove(Player* player, Map map){

    Vector2 newPosition;


    if(IsKeyDown(KEY_W)){
        
        newPosition.x = player->position.x + player->direction.x * player->movementSpeed;
        newPosition.y = player->position.y + player->direction.y * player->movementSpeed;

        if (mapIsTilePassThrought(map, newPosition)){
            player->position.x = newPosition.x;
            player->position.y = newPosition.y; 
        }
        
    }else if(IsKeyDown(KEY_S)){
        newPosition.x = player->position.x - player->direction.x * player->movementSpeed;
        newPosition.y = player->position.y - player->direction.y * player->movementSpeed;
        
        if(mapIsTilePassThrought(map, newPosition)){
            player->position.x = newPosition.x;
            player->position.y = newPosition.y; 
        }
    }

    if(IsKeyDown(KEY_A)){
        newPosition.x = player->position.x + cos(player->angle - 90 * DEG2RAD) * player->movementSpeed;
        newPosition.y = player->position.y + sin(player->angle - 90 * DEG2RAD) * player->movementSpeed;
        
        if(mapIsTilePassThrought(map, newPosition)){
            player->position.x = newPosition.x;
            player->position.y = newPosition.y; 
        }
    }else if(IsKeyDown(KEY_D)){
        newPosition.x = player->position.x + cos(player->angle + 90 * DEG2RAD) * player->movementSpeed;
        newPosition.y = player->position.y + sin(player->angle + 90 * DEG2RAD) * player->movementSpeed;
        
        if(mapIsTilePassThrought(map, newPosition)){
            player->position.x = newPosition.x;
            player->position.y = newPosition.y; 
        }
    }
}

void playerRotate(Player* player) {
    if(IsKeyDown(KEY_LEFT)){
        player->angle -= PLAYER_ROTATION_SPEED;
    }else if (IsKeyDown(KEY_RIGHT)){
        player->angle += PLAYER_ROTATION_SPEED;
    }

    if(player->angle > 360 * DEG2RAD){
        player->angle = 0;
    }
    else if(player->angle < 0){
        player->angle = 360 * DEG2RAD;
    }

    player->direction.x = cos(player->angle);
    player->direction.y = sin(player->angle);
}