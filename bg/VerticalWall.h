#ifndef VERTICALWALL_H
#define VERTICALWALL_H

#include "Barrier.h"

struct VerticalWall: public Barrier {
  using Barrier::Barrier;
  char getChar() const noexcept override;
};

#endif
