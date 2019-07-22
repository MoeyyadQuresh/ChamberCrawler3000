#ifndef POTION_H
#define POTION_H

#include "../Item.h"

class Potion: public Item {
  bool knownName;
  char getChar() const noexcept override;
};

#endif
