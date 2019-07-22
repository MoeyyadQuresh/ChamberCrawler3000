#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "Background.h"

struct FloorTile: public Background {
  using Background::Background;
  
  char getChar() const noexcept override;
  bool passable(const Character&) const noexcept override; //Always passable
};

#endif
