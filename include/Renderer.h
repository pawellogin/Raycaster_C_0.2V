#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include "Map.h"
#include "Player.h"
#include "Raycaster.h"
#include <math.h>

Color rendererDarkenColor(Color color, float shadowPower);
Color rendererLimitDarknessTo(Color color, Color limit);
void rendererDrawWallsSolidColor(Player player,Map map);
void rendererDrawCeiling(Color color);
void rendererDrawFloor(Color color);


#endif