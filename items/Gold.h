#ifndef GOLD_H
#define GOLD_H

#include "Item.h"

//Do not create directly
class Gold: public Item {
public:
  using Item::Item;
  
  bool isGold = true;
  char getChar() const noexcept;
};

#endif
