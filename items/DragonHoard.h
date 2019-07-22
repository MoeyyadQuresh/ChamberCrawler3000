#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "Gold.h"

struct DragonHoard: public Gold {
  using Gold::Gold;
  int quantity = 6;
  bool canPickup = false;
};

#endif
