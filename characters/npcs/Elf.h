#ifndef ELF_H
#define ELF_H

#include "NPC.h"

class Elf: public NPC {

public:
  using NPC::NPC;

  const int defaultHP = 140;
  const int defaultAttack = 30;
  const int defaultDefense = 10;
  
  int speed = 2; //Attacks twice per turn
  
  char getChar() const noexcept override;
};

#endif
