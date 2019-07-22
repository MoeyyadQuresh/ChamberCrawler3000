#include "Position.h"
#include <cstdlib>

Position::Position(int x, int y):
  x{x}, y{y} {}

bool Position::inRadius(int radius, Position& pos) const noexcept {
  int xDist = std::abs(this->x - pos.x);
  int yDist = std::abs(this->y - pos.y);
  
  return xDist <= radius && yDist <= radius;
}


bool operator==(const Position& lhs,const Position& rhs) {
    return (lhs.x==rhs.x && lhs.y==rhs.y);
}


bool Position::isNearby(Position& pos) const noexcept {
  return this->inRadius(1, pos);
}
