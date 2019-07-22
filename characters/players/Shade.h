#ifndef SHADE_H
#define SHADE_H

#include "Player.h"

class Shade: public Player {
  double getScoreMultiplier() const noexcept;
public:
  using Player::Player;
  int getScore() const noexcept override;
};

#endif
