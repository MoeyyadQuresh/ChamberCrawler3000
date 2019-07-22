#ifndef PLAYER_H
#define PLAYER_H

#include "../../Tile.h"
#include "../Character.h"
#include <string>
#include <vector>

class Player: public Character {
  void attackByDirection(const std::string& dir);
  void tryPickup();

protected:
  int tryMoveToTile(Tile& dest);

public:
  using Character::Character;

  const int defaultHP = 125;
  const int defaultAttack = 25;
  const int defaultDefense = 25;

  int gold = 0;
  const bool isPlayer = true;
  int attackControl(const std::string& input);
  virtual int getScore() const noexcept;
  bool isOnStair() const;
  
  char getChar() const noexcept override;
  void update() override;
  void onDeath() override;
  void reset();
};

#endif
