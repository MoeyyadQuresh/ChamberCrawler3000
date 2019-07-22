#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H

#include "Gold.h"

struct MerchantHoard: public Gold {
  using Gold::Gold;
  int quantity = 4;
};

#endif
