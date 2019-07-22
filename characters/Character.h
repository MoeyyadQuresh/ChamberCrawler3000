#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <string>
#include <vector>
#include "../global.h"
#include "../items/Item.h"
#include "../Tile.h"

//Forward declaration
class Item;
class Position;
class Potion;
class Tile;

class Character {
  
  void dropInventory();

protected:
  int maxHealth;
  int tryMoveToTile(Tile& dest);

public:
  int defaultHP;
  int defaultAttack;
  int defaultDefense;
  void initStats();

  int health;
  int attack;
  int defense;
  int speed = 1;
  float evasion = 1;

  bool isGoblin = false;
  bool poisonBlood = false;

  int gold;

  std::vector<std::shared_ptr<Item>> inventory;

  const bool isPlayer = false;
  bool hasUpdated = false; //Reset every turn

  //Must be defined before game starts
  Tile* tilePtr;
  
  //Defines attack, defense, health using childrens' defaults
  Character();
  Character(Tile* ptr);
  
  virtual char getChar() const noexcept = 0;
  virtual void update() = 0;
  
  virtual int attackChar(Character& c);
  virtual int getAttack(const Character& c) const noexcept;
  virtual int getDefense(const Character& c) const noexcept;
  virtual void getHit(Character& c, int damage); //Calls modifyHealth
  virtual void hasKilled(Character& c);
  virtual void onDeath(); //Delete own pointer on tile and drop inventory

  virtual int takePotion(Potion& p);
  int takePotion(const std::string& dir);


  bool isDead() const noexcept;
  int move(const std::string& dir);
  int move(int x, int y);
  void printMessage(std::string race, int level, std::string action) const;

  //Syntactic sugar
  Position& getPos() const noexcept;
  int getX() const noexcept;
  int getY() const noexcept;

  void addInv(std::shared_ptr<Item> item);

  //Will modify the attack, defense, health fields
  //Child classes will perform special actions after calling parent method
protected:
  void modifyAttack(int quantity);
  void modifyDefense(int quantity);
  void modifyHealth(int quantity);
};

#endif
