#ifndef PASSAGE_H
#define PASSAGE_H

#include "PlayerExclusive.h"

struct Passage: public PlayerExclusive {
  using PlayerExclusive::PlayerExclusive;
  char getChar() const noexcept override;
};

#endif
