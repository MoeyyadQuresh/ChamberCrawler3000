#ifndef THEVOID_H
#define THEVOID_H

#include "Barrier.h"

struct TheVoid: public Barrier {
  using Barrier::Barrier;
  char getChar() const noexcept override;
};

#endif
