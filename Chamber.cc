#include "Chamber.h"
#include <cstdlib>

Chamber::Chamber(): positions{} {}

Chamber::~Chamber() {}

Position& Chamber::getRandomPosition() {
    int randind = rand() % positions.size();
    return positions[randind];
}
