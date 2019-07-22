#ifndef DRAGON_H
#define DRAGON_H

#include <memory>
#include "NPC.h"

#include "../../items/DragonHoard.h"

class Dragon: public NPC {
  std::shared_ptr<Item> hoard;
  const static int ANGER_RADIUS = 1;

  void autoMove() noexcept override;

public:
  const int defaultHP = 150;
  const int defaultAttack = 20;
  const int defaultDefense = 20;
  
  Dragon(Tile* ptr, std::shared_ptr<Item> hoard);
  
  char getChar() const noexcept override;
  bool isHostile() const override;
  void onDeath() override;
};

#endif
