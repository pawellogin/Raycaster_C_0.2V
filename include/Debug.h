#ifndef DEBUG_H
#define DEBUG_H
#include "./include/Player.h"
#include "./include/Renderer.h"
#include "./include/MiniMap.h"
#include "./include/Map.h"
#include "./include/Tile.h"
#include "./config/rendererConfig.h"
#include "./config/screenConfig.h"


void debugShowPlayerInfo(Player player, Map map);
void debugShowMinMap(Player player, Map map);
void debugShowHintInfo();


#endif