#ifndef DOORWAY_H
#define DOORWAY_H

#include "PlayerExclusive.h"

struct Doorway: public PlayerExclusive {
  using PlayerExclusive::PlayerExclusive;
  char getChar() const noexcept override;
};

#endif
