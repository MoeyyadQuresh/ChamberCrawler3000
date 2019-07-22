#include "FloorTile.h"

char FloorTile::getChar() const noexcept {
  return '.';
//  return "\033[1;31m.\033[1;0m";
}

bool FloorTile::passable(const Character&) const noexcept {
  return true;
}
