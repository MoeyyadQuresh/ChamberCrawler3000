#ifndef GLOBAL_H
#define GLOBAL_H

#include <memory>

class Floor;
class Player;

extern int level;
extern Floor* f;
extern std::shared_ptr<Player> player;
extern bool doMovement;
extern bool angryMerchant;


#endif
