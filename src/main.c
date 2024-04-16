#include "raylib.h"
#include "./include/Map.h"
#include "./include/Player.h"
#include "./include/MiniMap.h"
#include "./include/Renderer.h"
#include "./config/rendererConfig.h"
#include "./config/screenConfig.h"
#include "./include/Debug.h"

int main(){

    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;
    InitWindow(screenWidth, screenHeight, "raycaster");

    const int targetFPS = TARGET_FPS;
    SetTargetFPS(targetFPS);  

    Map* map = mapCreateEmptyWithBarriers();
    Player player = playerCreate();

    bool showDebug = false;
    bool debugNeverOnceShown = true;
         
    while(!WindowShouldClose()){


        playerMove(&player, *map);
        playerRotate(&player);
        mapCreateTestRoom(map);

        BeginDrawing();

            ClearBackground(BLACK);
            rendererDrawCeiling(CEILING_COLOR);
            rendererDrawFloor(FLOOR_COLOR);
            rendererDrawWallsSolidColor(player, *map);

            if(debugNeverOnceShown) debugShowHintInfo();

            if(IsKeyPressed(KEY_F3)){
                showDebug = !showDebug;
                debugNeverOnceShown = false;
            }

            if(showDebug){    
                debugShowMinMap(player, *map);
                debugShowPlayerInfo(player, *map);
            }
            
        EndDrawing();


    }
    CloseWindow();

    mapFreeMapGrid(map);
    free(map);

    return 0;
}