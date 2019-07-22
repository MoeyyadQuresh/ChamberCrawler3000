#ifndef HALFLING_H
#define HALFLING_H

#include "NPC.h"

class Halfling: public NPC {

public:
  using NPC::NPC;

  const int defaultHP = 100;
  const int defaultAttack = 15;
  const int defaultDefense = 20;

  float evasion = 0.5;

  char getChar() const noexcept override;
};

#endif
