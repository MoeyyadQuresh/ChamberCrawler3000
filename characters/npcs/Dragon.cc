#include "Dragon.h"
#include "../../Tile.h"

Dragon::Dragon(Tile* ptr, std::shared_ptr<Item> hoard):
  hoard{hoard}{
  tilePtr = ptr;
}

char Dragon::getChar() const noexcept {
  return 'D';
}

//If player is near self or hoard
bool Dragon::isHostile() const {
  return  (this->tilePtr->playerNearby(ANGER_RADIUS) ||
           this->hoard->tilePtr->playerNearby(ANGER_RADIUS));
}

void Dragon::autoMove() noexcept {
  //Do nothing, stay still
}


void Dragon::onDeath() {
  this->hoard->canPickup = true;
  Character::onDeath(); //Delete own pointer
}
