#ifndef MERCHANT_H
#define MERCHANT_H

#include "NPC.h"

class Merchant: public NPC {
public:
//  static bool hostileToPlayer;
  
  const int defaultHP = 30;
  const int defaultAttack = 70;
  const int defaultDefense = 5;
  
  Tile* tilePtr;
  Merchant(Tile* ptr);
  
  char getChar() const noexcept override;
  void getHit(Character& c, int damage) override;
  bool isHostile() const override;
};

//bool Merchant::hostileToPlayer = false;

#endif
