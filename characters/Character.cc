#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>

#include "Character.h"
#include "../getTile.h"
#include "../items/Item.h"

Character::Character(){
  health = this->defaultHP;
  maxHealth = this->defaultHP;
  attack = this->defaultAttack;
  defense = this->defaultDefense;
  tilePtr = nullptr;
}

//Superclass constructor is implicitly called
//Child classes use this to define health, attack, defense
//Using the default property values children define
Character::Character(Tile* ptr):
  health{this->defaultHP},
  maxHealth{this->defaultHP},
  attack{this->defaultAttack},
  defense{this->defaultDefense},
  tilePtr{ptr}
 {}

int Character::attackChar(Character& c) {
  //Check evasion
  float randNum = (std::rand() % 1001) / 1000;
  
  if (randNum < c.evasion){
    //Do attack
    int attackStrength = this->getAttack(c);
    int targetDefense = c.getDefense(*this);
    
    int damage = std::ceil((100/(100+targetDefense))*attackStrength);
    c.getHit(*this, damage);
    
    //For children to override
    if (c.isDead()){
      this->hasKilled(c);
      c.onDeath();
    }
  } else { //Miss
    return 3;
  }
}

int Character::getAttack(const Character&) const noexcept {
  return this->attack;
}

int Character::getDefense(const Character&) const noexcept {
  return this->defense;
}

//For children to override
void Character::getHit(Character&, int) {}

//By default do nothing
void Character::hasKilled(Character&) {}

bool Character::isDead() const noexcept {
  return this->health <= 0;
}

void Character::printMessage(std::string race, int level, std::string action) const {

    std::cout << "Race: " << race << " Gold: " << gold;
    std::cout << "                                             Floor " << level << std::endl;
    std::cout << "HP: " << health << std::endl;
    std::cout << "Atk: " << attack << std::endl;
    std::cout << "Def: " << defense << std::endl;
    std::cout << "Action: " << action << std::endl;
}

int Character::move(int x, int y){
  Tile* dest = getTile(x, y);
  return this->tryMoveToTile(*dest);
}

int Character::move(const std::string& dir){
  Tile& dest = this->tilePtr->getByDirection(dir);
  return this->tryMoveToTile(dest);
}

void Character::onDeath(){
  this->dropInventory();
  this->tilePtr->character.reset(); //Commits suicide
}

//Consume potion in direction
int Character::takePotion(const std::string& dir){
    
    
    return 1;
}

int Character::takePotion(Potion& p){
    
    
    return 1;

}

//All items
//TODO Expand radially instead
void Character::dropInventory(){
  int xOffset = 0;
  int yOffset = 0;
  
  //Initially try to drop item on current position
  Tile* dest = this->tilePtr;
  
  for (unsigned int i = 0; i < this->inventory.size(); ++i){
    //If can't drop on current spot
    if (dest->item){
      for (int i = 0; i < 9; ++i){ //Search radius
        xOffset = i % 3 - 1;
        yOffset = i / 3 - 1;
        
        int xIndex = this->getX() + xOffset;
        int yIndex = this->getY() + yOffset;
        
        dest = getTile(xIndex, yIndex);
        if (!(dest->item)) break; //Found free tile
      }
    }
    
    //Place item and "nullify" inventory's pointer
    dest->item = std::move(this->inventory[i]);
    dest->item->tilePtr = dest;
  }
  //Inventory is full of nullptrs
  this->inventory.resize(0);
}

int Character::tryMoveToTile(Tile& dest){
  int res = dest.passable(*this);

  if (res == 1){
    this->tilePtr->moveCharacter(dest);
  }

  return res;
}

Position& Character::getPos() const noexcept{
  return this->tilePtr->pos;
}

int Character::getX() const noexcept {
  return this->getPos().x;
}

int Character::getY() const noexcept {
  return this->getPos().y;
}

void Character::addInv(std::shared_ptr<Item> item){
  this->inventory.push_back(std::move(item));
}

void Character::modifyAttack(int quantity){
  this->attack += quantity;

  if (this->attack < 0){
    this->attack = 0;
  }
}

void Character::modifyDefense(int quantity){
  this->defense += quantity;

  if (this->defense < 0){
    this->defense = 0;
  }
}

void Character::modifyHealth(int quantity){
  this->health += quantity;

  if (this->health > this->maxHealth){
    this->health = this->maxHealth;
  }
}

void Character::initStats(){
  this->health = this->defaultHP;
  this->maxHealth = this->defaultHP;
  this->attack = this->defaultAttack;
  this->defense = this->defaultDefense;
}
