#ifndef NORMAL_PILE_H
#define NORMAL_PILE_H

#include "Gold.h"

struct NormalPile: public Gold {
  using Gold::Gold;
  int quantity = 2;
};

#endif
