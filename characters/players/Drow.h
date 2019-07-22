#ifndef DROW_H
#define DROW_H

#include "Player.h"

class Drow: public Player {
public:
  using Player::Player;
  const int defaultHP = 150;
  const int defaultAttack = 25;
  const int defaultDefense = 15;

  int speed = 2;
  
//  int takePotion(Potion& p) override;
};

#endif
