#include "raylib.h"
#include "./include/Map.h"
#include "./include/Player.h"
#include "./include/MiniMap.h"

int main(){

    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raycaster");

    SetTargetFPS(60);  

    Map* map = mapCreateEmptyWithBarriers();
    Player player = playerCreate();
         
    while(!WindowShouldClose()){



        playerMove(&player, *map);
        playerRotate(&player);


        BeginDrawing();

            ClearBackground(BLACK);

            miniMapDrawMiniMap(player, *map);
        EndDrawing();


    }
    CloseWindow();

    return 0;

    return 0;
}