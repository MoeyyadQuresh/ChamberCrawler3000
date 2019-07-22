#ifndef HUMAN_H
#define HUMAN_H

#include "NPC.h"

class Human: public NPC {
public:
  Tile* tilePtr; //Kludge
  Human(Tile* ptr);

  const int defaultHP = 140;
  const int defaultAttack = 20;
  const int defaultDefense = 20;
  
  int gold = 2; //TODO: Verify two normal piles

  char getChar() const noexcept override;
};

#endif
