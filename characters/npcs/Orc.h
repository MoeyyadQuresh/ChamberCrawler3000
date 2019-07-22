#ifndef ORC_H
#define ORC_H

#include "NPC.h"

class Orc: public NPC {

public:
  using NPC::NPC;

  const int defaultHP = 180;
  const int defaultAttack = 30;
  const int defaultDefense = 25;

  int getAttack(const Character& c) const noexcept override;
  char getChar() const noexcept override;
};

#endif
