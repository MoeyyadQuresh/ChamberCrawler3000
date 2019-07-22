#ifndef HORIZONTALWALL_H
#define HORIZONTALWALL_H

#include "Barrier.h"

struct HorizontalWall: public Barrier {
  using Barrier::Barrier;
  char getChar() const noexcept override;
};

#endif
