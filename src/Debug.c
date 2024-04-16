#include "./include/Debug.h"

void debugShowPlayerInfo(Player player, Map map){

   Vector2 drawPosOnScreen = {
        10,
        10
    };
    int fontSize = 20;
    float textSpacing = 20;
    int textNumber = 0;
    const Color TEXT_COLOR = BLACK;

    char fpsText[20];
    snprintf(fpsText,sizeof(fpsText),"Fps: = %d", GetFPS());
    DrawText(fpsText, drawPosOnScreen.x,drawPosOnScreen.y + (textSpacing * textNumber), fontSize, TEXT_COLOR);
    textNumber++;

    char positionText[40];
    snprintf(positionText,sizeof(positionText),"Position: X = %.2f Y = %.2f",player.position.x, player.position.y);
    DrawText(positionText, drawPosOnScreen.x, drawPosOnScreen.y + (textSpacing * textNumber), fontSize,TEXT_COLOR);
    textNumber++;

    char angleText[40];
    snprintf(angleText,sizeof(angleText),"Angle: %.2f",player.angle * RAD2DEG);
    DrawText(angleText,drawPosOnScreen.x, drawPosOnScreen.y + (textSpacing * textNumber), fontSize,TEXT_COLOR);
    textNumber++;

    char singleRayLength[40];
    TileToDraw* tileArray = NULL;
    size_t tileArraySize = 0;

    tileArray = raycasterCastRay(player, map, &tileArraySize);
    snprintf(singleRayLength,sizeof(singleRayLength),"Single ray length: %.2f",tileArray[0].rayLength);
    DrawText(singleRayLength,drawPosOnScreen.x ,drawPosOnScreen.y + (textSpacing * textNumber), fontSize,TEXT_COLOR);
    textNumber++;

    char pointingAtTileText[40];
    TileName tileName = tileArray[0].name;
    snprintf(pointingAtTileText, sizeof(pointingAtTileText), "Pointing at tile: %s", tileNameToString(tileName));
    DrawText(pointingAtTileText, drawPosOnScreen.x, drawPosOnScreen.y + (textSpacing * textNumber), fontSize, TEXT_COLOR);
    textNumber++;

    if(tileArray != NULL){
        free(tileArray);
    }
}

void debugShowMinMap(Player player, Map map){
            miniMapDrawMiniMap(player, map);
            miniMapRaycastSingleRay(player,map);
}

void debugShowHintInfo(){
    Vector2 drawPosOnScreen = {
        SCREEN_WIDTH/2.5f,
        0
    };

    char hintText[] = "Press F3 for debug mode";
    DrawText(hintText, drawPosOnScreen.x,drawPosOnScreen.y,20, BLACK);
}
