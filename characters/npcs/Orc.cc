#include "Orc.h"

int Orc::getAttack(const Character& c) const noexcept {
  float multiplier;
  if (c.isGoblin){
    multiplier = 1.5;
  } else {
    multiplier = 1;
  }

  return NPC::getAttack(c) * multiplier;
}

char Orc::getChar() const noexcept {
  return 'O';
}
