#ifndef DWARF_H
#define DWARF_H

#include "NPC.h"

class Dwarf: public NPC {

public:
  using NPC::NPC;

  const int defaultHP = 100;
  const int defaultAttack = 20;
  const int defaultDefense = 30;
  bool poisonBlood = true;

  char getChar() const noexcept override;
};

#endif
