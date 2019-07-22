#ifndef NPC_H
#define NPC_H

#include "../Character.h"

class NPC: public Character {
  int gold = 0;

  bool autoAttack();
  virtual void autoMove();

public:
  using Character::Character;

  virtual int attackChar(Character& c) override;
  virtual bool isHostile() const;
  void update() override;
};

#endif
