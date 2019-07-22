#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include "../characters/Character.h"

struct Background {
  const bool isStair = false;
  
  virtual char getChar() const noexcept = 0;
  virtual bool passable(const Character& c) const noexcept = 0;
};

#endif
