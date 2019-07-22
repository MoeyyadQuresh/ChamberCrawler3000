#ifndef STAIR_H
#define STAIR_H

#include "PlayerExclusive.h"

struct Stair: public PlayerExclusive {
  using PlayerExclusive::PlayerExclusive;
  const bool isStair = true;
  char getChar() const noexcept override;
};

#endif
