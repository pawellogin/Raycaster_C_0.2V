#include "./include/Renderer.h"
#include "./config/rendererConfig.h"
#include "./config/screenConfig.h"


Color rendererDarkenColor(Color color, float shadowPower) {
    Color darkColorLimit = {40,40,40,255};

    if(shadowPower > 1) color = darkColorLimit;
    else{
        float shadow = color.r * shadowPower;
        color.r -= shadow;

        shadow = color.g * shadowPower;
        color.g -= shadow;

        shadow = color.b * shadowPower;
        color.b -= shadow;

        color = rendererLimitDarknessTo(color, darkColorLimit);

    }

    return color;
}

Color rendererLimitDarknessTo(Color color, Color limit){
    Color result = color;
    if(result.r < limit.r) result.r = limit.r;
    if(result.g < limit.g) result.g = limit.g;
    if(result.b < limit.b) result.b = limit.b;

    return result;
}


void rendererDrawWallsSolidColor(Player player,Map map){
    float startAngle = player.angle;
    float rayAngle = startAngle - player.FOV/2;

    Vector2 drawPosisiton = {0.0f,0.0f};
    float drawHeight = 0.0f;
    float basicHeight = 0.0f;
    float shadowPower = 0.0f;
    Color wallColor = {0,0,0,255};

    TileToDraw* tileArray = NULL;
    size_t tileArraySize = 0;
    bool wallsConnected = false;

    for(size_t i = 0; i < SCREEN_WIDTH; i++){
        tileArray = raycasterCastRay(player, map, &tileArraySize);
        
        for(size_t j = tileArraySize - 1; j != SIZE_MAX; j--){

            if (j >= 1) {
            if ((abs(tileArray[j].cords.x - tileArray[j-1].cords.x) <= 1) && (abs(tileArray[j].cords.y - tileArray[j-1].cords.y) <= 1) && ((tileArray[j].cords.x == tileArray[j-1].cords.x) || (tileArray[j].cords.y == tileArray[j-1].cords.y))) {
                    wallsConnected = true;
                }else {
                    wallsConnected = false;
                }
            } 

            if(j >= 1 && tileArray[j-1].isTransparent && tileArray[j].isTransparent && wallsConnected){
                continue;
            }

            drawPosisiton.x = i;
            drawHeight = (SCREEN_HEIGHT / tileArray[j].rayLength) * tileArray[j].height;
            basicHeight = (SCREEN_HEIGHT / tileArray[j].rayLength);

            drawPosisiton.y = ((SCREEN_HEIGHT - basicHeight) / 2) + basicHeight - drawHeight;

            if(tileArray[j].side == VERTICAL){
                shadowPower = tileArray[j].rayLength * SHADOW_POWER;
            }
            else if(tileArray[j].side == HORIZONTAL) {
                shadowPower = tileArray[j].rayLength * (SHADOW_POWER * 3);
            }
            wallColor = tileArray[j].color;
            wallColor = rendererDarkenColor(wallColor,shadowPower);

            DrawRectangleV(drawPosisiton, (Vector2){1,drawHeight}, wallColor);
        }

        if(tileArray != NULL){
            free(tileArray);
        }

        float rayAngleStepSize = player.FOV / SCREEN_WIDTH;
        rayAngle += rayAngleStepSize;
        player.direction = (Vector2){cos(rayAngle),sin(rayAngle)};
    }

}

void rendererDrawCeiling(Color color){
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT/2, color);
}

void rendererDrawFloor(Color color){
    DrawRectangle(0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2, color);
}
