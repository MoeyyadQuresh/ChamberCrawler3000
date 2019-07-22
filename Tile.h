#ifndef TILE_H
#define TILE_H

#include "Position.h"
#include <memory>
#include <vector>
#include <string>

//Forward declarations
class Background;
class Character;
class Item;

struct Tile {
  std::shared_ptr<Character> character;
  std::unique_ptr<Background> background; //Default is TheVoid
  std::shared_ptr<Item> item;
  Position pos;

  Tile();
  Tile(int x, int y);
  
  std::vector<Tile*> getAdjacent() const;

  Tile& getByDirection(const std::string& dir) const;

  char getChar() const; //Print the displayed character on screen
  bool playerNearby(int radius=1) const;
  
  //Syntactic sugar
  bool hasPlayer() const;
  int getX() const;
  int getY() const;
  
  //Move own character to another tile, must have one
  void moveCharacter(int x, int y); //Use x and y positions
  void moveCharacter(Tile& t); //Use tile reference
  void resetTileUpdate();
  void update();
  int passable(const Character& c) const;
  bool canHoldItem() const;

  void print() const;
};

#endif
