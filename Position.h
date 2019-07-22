#ifndef POSITION_H
#define POSITION_H

struct Position {
  int x;
  int y;
  
  Position(int x, int y);
  bool inRadius(int radius, Position& pos) const noexcept;
  bool isNearby(Position& pos) const noexcept;
};

bool operator==(const Position& lhs,const Position& rhs);

#endif
