#include "Tile.h"

#include "getTile.h"
#include "characters/Character.h"
#include "characters/players/Player.h"
#include "bg/TheVoid.h"
#include "items/Item.h"
#include "global.h"
#include <iostream>

Tile* getTile(int x, int y);

Tile::Tile(): pos{Position(0,0)} {}


Tile::Tile(int x, int y): pos{Position{x, y}}{
  background.reset(new TheVoid{});
}


char Tile::getChar() const {
  if (this->character){
    return this->character->getChar();
  } else if (this->item){
    return this->item->getChar();
  } else if  (this->background){
    return this->background->getChar();
  } else {
    std::cout << "ERROR" << std::endl;
  }
}

bool Tile::hasPlayer() const {
  return (this->character && this->character->isPlayer);
}

int Tile::getX() const {
  return this->pos.x;
}

int Tile::getY() const {
  return this->pos.y;
}

std::vector<Tile*> Tile::getAdjacent() const {
  std::vector<Tile*> result;
  
  for (int xOffset = -1; xOffset <= 1; ++xOffset){
      for (int yOffset = -1; yOffset <= 1; ++yOffset){
      //Skip self
      if (xOffset == 0 && yOffset == 0) continue;
      
      int xIndex = this->getX() + xOffset;
      int yIndex = this->getY() + yOffset;
      //Get tile by index and push
      //result.push_back(xIndex... yIndex...);
    }
  }

  return result;
}

//Arg: Direction
//e.g. no,so,ea,we,ne,nw,se,sw
Tile& Tile::getByDirection(const std::string& dir) const {
  int xOffset;
  int yOffset;

  if (dir == "no"){
    xOffset = 0;
    yOffset = -1;
  } else if (dir == "so"){
    xOffset = 0;
    yOffset = 1;
  } else if (dir == "ea"){
    xOffset = 1;
    yOffset = 0;
  } else if (dir == "we"){
    xOffset = -1;
    yOffset = 0;
  } else if (dir == "ne"){
    xOffset = 1;
    yOffset = -1;
  } else if (dir == "nw"){
    xOffset = -1;
    yOffset = -1;
  } else if (dir == "se"){
    xOffset = 1;
    yOffset = 1;
  } else if (dir == "sw"){
    xOffset = -1;
    yOffset = 1;
  }
    
  int xIndex = this->getX() + xOffset;
  int yIndex = this->getY() + yOffset;


  Tile *ret = getTile(xIndex, yIndex);
    
    return *ret;
}

//Requires player global variable
bool Tile::playerNearby(int radius) const {
  //For now let "player" denote the pointer to player
  Position& playerPos = player->getPos();
  
  return this->pos.inRadius(radius, playerPos);
}

void Tile::moveCharacter(int x, int y){
  //Get the Tile reference from the vector of tiles
  Tile* t = getTile(x, y);
  //Define as reference t
  this->moveCharacter(*t);
}

void Tile::moveCharacter(Tile& t){
  if (!this->character){
//    throw runtime_error("Tried to move character with empty tile.");
  } else if (t.passable(*(this->character)) != 1){
//    throw runtime_error("Could not move character to unpassable tile.");
  }
  
  //Change character's tilePtr to new tile
  this->character->tilePtr = &t;
  
  //Make new tile's character pointer point to character
  std::swap(this->character, t.character);
}

void Tile::resetTileUpdate(){
  if (this->character){
    this->character->hasUpdated = false;
  }
}

void Tile::update(){

  if (this->character){
#ifdef DEBUG
      std::cout << "[DebugMessage: a character is on the tile]" << std::endl;
#endif
    this->character->update();
#ifdef DEBUG
      std::cout << "[DebugMessage: character updated]" << std::endl;
#endif
  }
}

int Tile::passable(const Character& c) const {
  if (!this->background->passable(c)){
    return 2;
  }
  else if (this->character){
    return 3;
  } else {
    return 1; //Successful
  }
}

//Kludge solution, only spawn where player can exist
bool Tile::canHoldItem() const {
  Player temp = Player();
  return this->passable(temp);
}

void Tile::print() const {
  std::cout << "X, Y: (" << this->getX() << ", " << this->getY() << ")" << std::endl;
}
