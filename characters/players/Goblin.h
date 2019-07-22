#ifndef GOBLIN_H
#define GOBLIN_H

#include "Player.h"

class Goblin: public Player {
public:
  using Player::Player;
  
  const int defaultHP = 110;
  const int defaultAttack = 15;
  const int defaultDefense = 20;
  
  bool isGoblin = true;
  
  //Steal 5 gold from every slain enemy
  void hasKilled(Character& c) override;
};

#endif
