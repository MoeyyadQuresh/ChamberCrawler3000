#include "Shade.h"

//DLC feature, purity of Shade
double Shade::getScoreMultiplier() const noexcept {
  return 0.5;
}

int Shade::getScore() const noexcept {
  return Player::getScore() + Player::getScore() * this->getScoreMultiplier();
}
