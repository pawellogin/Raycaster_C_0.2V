#ifndef MINIMAP_H
#define MINIMAP_H

#include "Map.h"
#include "Player.h"

Vector2 miniMapGiveConvertedCords(Vector2 cords);
void miniMapDrawMiniMap(Player player,Map map);
void miniMapRaycastSingleRay(Player player, Map map);


#endif