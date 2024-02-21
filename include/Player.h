#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "map.h"
#include "./config/playerConfig.h"
#include <math.h>
#include <stdio.h>

typedef struct Player {
    Vector2 position;
    Vector2 direction;
    float angle;
    float FOV;
    float movementSpeed;
}Player;

Player playerCreate();

void playerMove(Player * player,Map map);
void playerRotate(Player* player);
void playerChangeFOV();
void playerChangeFOVForSprint(float change);
void playerSprint();

#endif