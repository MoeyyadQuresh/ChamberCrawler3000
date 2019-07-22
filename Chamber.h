#ifndef CHAMBER_H
#define CHAMBER_H

#include "Position.h"
#include <vector>

struct Chamber {
  std::vector<Position> positions;
    
  Chamber();
  ~Chamber();
  Position& getRandomPosition();
};

#endif

