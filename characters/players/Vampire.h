#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Player.h"

class Vampire: public Player {
public:
  const int defaultHP = 50;
  const int defaultAttack = 25;
  const int defaultDefense = 25;

  Vampire();

  int attackChar(Character& c) override;
};

#endif
