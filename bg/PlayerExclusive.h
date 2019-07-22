#ifndef PLAYEREXCLUSIVE_H
#define PLAYEREXCLUSIVE_H

#include "Background.h"

struct PlayerExclusive: public Background {
  using Background::Background;
  bool passable(const Character& c) const noexcept override; //Check if player
};

#endif
