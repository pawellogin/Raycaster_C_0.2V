#ifndef RAYCASTER_C
#define RAYCASTER_C

#include <math.h>
#include <stdlib.h>
#include "Map.h"
#include "TileToDraw.h"
#include "Player.h"
#include "./config/raycasterConfig.h"

TileToDraw* raycasterCastRay(Player player, Map map, size_t* tileArraySize);

#endif