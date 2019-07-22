#include "Merchant.h"
#include "../../items/MerchantHoard.h"

Merchant::Merchant(Tile* ptr):
  tilePtr{ptr}{
  this->addInv(std::unique_ptr<Item>(new MerchantHoard()));
}

//All merchants use same class variable
bool Merchant::isHostile() const {
  return angryMerchant;
}

void Merchant::getHit(Character& c, int damage){
  NPC::getHit(c, damage);
  if (c.isPlayer){
    angryMerchant = true;
  }
}

char Merchant::getChar() const noexcept {
  return 'M';
}
