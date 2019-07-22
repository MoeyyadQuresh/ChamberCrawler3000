#include <cstdlib>
#include "../../Position.h"
#include "NPC.h"
#include "../../getTile.h"
#include "../../global.h"
#include "../players/Player.h"
#include "../../getTile.h"

#include <iostream>

int NPC::attackChar(Character& c) {
  //Number of attacks depends on how fast compared to target
  int numAttacks = this->speed - c.speed + 1;
  
  int res;
  for (int i = 0; i < numAttacks; ++i){
    res = Character::attackChar(c);
  }
  return res; //Return last result
}

//Hostile by default
bool NPC::isHostile() const {
  return true;
}

void NPC::update(){
  if (!hasUpdated){
#ifdef DEBUG
      std::cout << "[DebugMessage: NPC::UPDATE: hasUpdated false]" << std::endl;
#endif
    if (!this->autoAttack()){
#ifdef DEBUG
        std::cout << "[DebugMessage: NPC::UPDATE: autoAttact() false, autoMove called]" << std::endl;
#endif
      //Move if not attacking
      this->autoMove();
#ifdef DEBUG
        std::cout << "[DebugMessage: NPC::UPDATE: post autoMove]" << std::endl;
#endif
    }
  }
}

//Default behaviour: Attack if player present and hostile
//Return whether tried to attack
bool NPC::autoAttack(){
#ifdef DEBUG
    std::cout << "[DebugMessage: NPC::AUTOATTACK]" << std::endl;
#endif
//    std::cout << this->tilePtr << std::endl;
  if (this->tilePtr->playerNearby() && this->isHostile()){
#ifdef DEBUG
      std::cout << "[DebugMessage: NPC::AUTOATTACK: in if]" << std::endl;
#endif
    //Attack code
    this->attackChar(*player);
    return true;
  }
  return false;
}

//Default behaviour: Random walk
void NPC::autoMove(){
  if (!doMovement) return; //Do nothing

  Position& current = this->getPos();
  int xOffset;
  int yOffset;

  int xIndex;
  int yIndex;

  //Randomly generate x and y index offsets
  for (int i = 0; i < 50; ++i) {
    xOffset = 1 - rand() % 3;
    yOffset = 1 - rand() % 3;

    xIndex = xOffset + current.x;
    yIndex = yOffset + current.y;

    //If can move to this tile - current tile is invalid
    if (xIndex >= 0 &&
        yIndex >= 0 &&
        getTile(xIndex, yIndex)->passable(*this) == 1) {
      break;
    }
  }
  this->move(xIndex, yIndex);
}


