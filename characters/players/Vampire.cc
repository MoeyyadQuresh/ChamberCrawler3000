#include "Vampire.h"

Vampire::Vampire() {
  maxHealth = 2147483647; //Max integer
}

int Vampire::attackChar(Character& c){
  int healthBoost;
  if (c.poisonBlood){
    healthBoost = -5;
  } else {
    healthBoost = 5;
  }

  this->modifyHealth(healthBoost);
  return Player::attackChar(c);
}
