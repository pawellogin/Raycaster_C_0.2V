#include "raylib.h"
#include "./include/Map.h"
#include "./include/Player.h"
#include "./include/MiniMap.h"
#include "./include/Renderer.h"
#include "./config/rendererConfig.h"
#include "./config/screenConfig.h"

int main(){

    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;
    InitWindow(screenWidth, screenHeight, "raycaster");

    const int targetFPS = TARGET_FPS;
    SetTargetFPS(targetFPS);  

    Map* map = mapCreateEmptyWithBarriers();
    Player player = playerCreate();
         
    while(!WindowShouldClose()){

        playerMove(&player, *map);
        playerRotate(&player);
        mapCreateTestRoom(map);

        BeginDrawing();

            ClearBackground(BLACK);
            rendererDrawCeling(CELING_COLOR);
            rendererDrawFloor(FLOOR_COLOR);
            rendererDrawWallsSolidColor(player, *map);
            miniMapRaycastSingleRay(player,*map);
            miniMapDrawMiniMap(player, *map);
            miniMapRaycastSingleRay(player, *map);

        EndDrawing();


    }
    CloseWindow();

    mapFreeMapGrid(map);
    free(map);

    return 0;
}