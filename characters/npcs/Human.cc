#include "Human.h"
#include "../../items/NormalPile.h"

Human::Human(Tile* ptr):
  tilePtr{ptr}{
  for (int i = 0; i < 2; ++i){
    this->addInv(std::unique_ptr<Item>(new NormalPile()));
  }
}

char Human::getChar() const noexcept {
  return 'H';
}
