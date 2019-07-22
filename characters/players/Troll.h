#ifndef TROLL_H
#define TROLL_H

#include "Player.h"

class Troll: public Player {
public:
  using Player::Player;
  const int defaultHP = 120;
  const int defaultAttack = 25;
  const int defaultDefense = 15;

  void update() override;
};

#endif
