#ifndef BARRIER_H
#define BARRIER_H

#include "Background.h"

struct Barrier: public Background {
  using Background::Background;
  bool passable(const Character&) const noexcept override; //Never passable
};

#endif
