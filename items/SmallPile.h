#ifndef SMALL_PILE_H
#define SMALL_PILE_H

#include "Gold.h"

struct SmallPile: public Gold {
  using Gold::Gold;
  int quantity = 1;
};

#endif
