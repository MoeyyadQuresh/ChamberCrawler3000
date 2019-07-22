#ifndef FLOOR_H
#define FLOOR_H

#include "Chamber.h"
#include "Tile.h"
#include "characters/players/Player.h"
#include <memory>
#include <vector>
#include <iostream>

#include "bg/Doorway.h"
#include "bg/Passage.h"
#include "bg/HorizontalWall.h"
#include "bg/VerticalWall.h"
#include "bg/FloorTile.h"
#include "bg/Stair.h"
#include "bg/TheVoid.h"

#include "characters/npcs/Human.h"
#include "characters/npcs/Halfling.h"
#include "characters/npcs/Merchant.h"
#include "characters/npcs/Elf.h"
#include "characters/npcs/Orc.h"
#include "characters/npcs/Dwarf.h"
#include "characters/npcs/Dragon.h"

#include "items/NormalPile.h"
#include "items/DragonHoard.h"
#include "items/SmallPile.h"
#include "items/potions/Potion.h"



struct Floor {
  Tile* tiles; //a vector to store the tiles
  Chamber* chambers; //an array of 5 chambers

  Floor();
  ~Floor();
  //init() reads in a map from a text file and stores contents in tiles
  void init();

  //spawnItems() randomly generates potions, treasure, and stairway on the floor
  void SpawnItems();
  //spawnEnemies() randomly generates enemies on the floor
  void SpawnEnemies();
  void SpawnPlayer(std::shared_ptr<Player> p);
  
  //printFloor() prints the floor with cout
  void printFloor();
  void npcMove();
  Tile* whichTile(int x, int y);
};

#endif

