#include "raylib.h"

int main(){

    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raycaster");

    SetTargetFPS(60);   

    while(!WindowShouldClose()){


        BeginDrawing();


        EndDrawing();


    }
    CloseWindow();

    return 0;

    return 0;
}