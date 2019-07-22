#include "Player.h"
#include "../../isDirection.h"
#include "../../bg/Background.h"
#include "../../isDirection.h"
#include <iostream>

int Player::attackControl(const std::string& input){
  Tile& dest = this->tilePtr->getByDirection(input);
  if (!dest.character){
    return -1; //No enemy found
  } else {
    return this->attackChar(*(dest.character));
  }
}

int Player::tryMoveToTile(Tile& dest) {
  int res = Character::tryMoveToTile(dest);
  
  this->tryPickup();
  return res;
}

void Player::tryPickup() {
  if (this->tilePtr->item){
    if (this->tilePtr->item->canPickup){
      if (this->tilePtr->item->isGold){
        this->gold += this->tilePtr->item->quantity;
        this->tilePtr->item.reset();
      } else {
        
        inventory.push_back(nullptr);
        std::swap(this->tilePtr->item, inventory[inventory.size() - 1]);
      }
    }
  }
}

char Player::getChar() const noexcept {
  return '@';
}

//Do nothing
//update runs during scan
//Player acts separately from other characters
void Player::update() {}

void Player::reset() {
  this->attack = this->defaultAttack;
  this->defense = this->defaultDefense;
}

int Player::getScore() const noexcept {
  return this->gold;
}

bool Player::isOnStair() const {
  return this->tilePtr->background->isStair;
}

void Player::onDeath() {
  Character::onDeath();
}
