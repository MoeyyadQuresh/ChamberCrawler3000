#ifndef ITEM_H
#define ITEM_H

#include <memory>

class Tile;

struct Item {
  Tile* tilePtr;

  Item(); //Items spawned in inventory have no tile pointer
  Item(Tile* ptr);

  bool canPickup = true; //By default, items can be picked up
  bool isGold = false;
  int quantity;
  virtual char getChar() const noexcept = 0;
};

#endif
