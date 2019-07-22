#include <memory>
#include <iostream>
#include "Floor.h"
#include "isDirection.h"

#include "characters/npcs/NPC.h"
#include "characters/npcs/Merchant.h"
#include "characters/players/Shade.h"
#include "characters/players/Drow.h"
#include "characters/players/Vampire.h"
#include "characters/players/Troll.h"
#include "characters/players/Goblin.h"

// for dlc structures, compile this program with tag -DDLC

//#include "global.h"
#include "debug.h"


int level;
Floor* f;
std::shared_ptr<Player> player;
bool doMovement;
bool angryMerchant;

int main() {

    doMovement = true;
    angryMerchant = false;
    f = new Floor[5];
    char c;
    std::string s;
    std::string dir;
    std::string race = "";
    int score;
    std::string message = "";
    int moveRetCode = 0;
    int takePotionCode = 0;
    int attackCode = 0;
    int purchaseCode = 0;

    pdebug("Pre While for playing again");
    while (1) { // Loop for playing again
        
        //Starting the game and choose a race
        std::cout << "Please choose your race (Shade|Drow|Vampire|Troll|Goblin)." << std::endl;
        std::cout << "Enter s|d|v|t|g to choose: ";
        while (race == "") { // Loop for reading races
            if (std::cin >> s) {
                if (s == "s") {
                    player = std::shared_ptr<Player>(new Shade());
                    race = "Shade";
                } else if (s == "d") {
                    player = std::shared_ptr<Player>(new Drow());
                    race = "Drow";
                } else if (s == "v") {
                    player = std::shared_ptr<Player>(new Vampire());
                    race = "Vampire";
                } else if (s == "t") {
                    player = std::shared_ptr<Player>(new Troll());
                    race = "Troll";
                } else if (s == "g") {
                    player = std::shared_ptr<Player>(new Goblin());
                    race = "Goblin";
                } else if (s == "q") {
                    return 0;
                } else {
                    std::cout << "Enter the code of a race: ";
                }
            } else if (std::cin.eof()) {
                return 0;
            }
        }
        //start the game
        for (level = 1; level <= 5; level++) {
            //spawing the items and enemies
            pdebug("Pre f[level].init()");
            f[level].init();

            //spawing the player
            pdebug("Pre f[level].SpawnPlayer(player)");
            f[level].SpawnPlayer(player);
            player->health = player->defaultHP;
            player->attack = player->defaultAttack;
            player->defense = player->defaultDefense;
            pdebug("Warning: all races are having same default stats.");
            //print the floor and message
            f[level].printFloor();
            pdebug("post printFloor");

            message = "Game started";
            player->printMessage(race,level,message);
            pdebug("Post printMessage");
            
            //Read in actions
            while (1) {
                pdebug("in while of reading actions");
                if (player->isDead()) {
                    pdebug("isDead() returned true");
                    s = "q";
                    break;
                } else if (std::cin >> s)  {
                    pdebug("cin succeeded");
                    if (player->isOnStair() || s == "r" || s == "q") {
                        //if reach the stair, restart or quit, break the loop
                        pdebug("isOnStair or Restart or Quit");
                        message = "You entered next level.";
                        break;
                    } else if (isDirection(s)) { //no so ea we ne nw se sw to move
                        pdebug("a direction detected");
                        moveRetCode = player->move(s);
                        pdebug("Post player->move(s)");
#ifdef DEBUG
                        std::cout << moveRetCode << std::endl;
#endif
                    } else if (s == "u") {
                        pdebug("pre reading direction");
                        std::cin >> dir;
                        takePotionCode = player->takePotion(dir);
                        pdebug("post takePotion");
                        //u <direction> to use the potion
                    } else if (s == "a") {
                        pdebug("in a");
                        std::cin >> dir;
                        if (isDirection(dir)){
                            attackCode = player->attackControl(dir);
                            pdebug("post attackControl");
                          //a <direction> to attack the enemy
                        }
                    } else if (s == "f") {
                        doMovement=!(doMovement);
                        //f to stop enemies from moving
                    }
                    #ifdef DLC
                    else if (s == "p" ) { // purchase potionform merchant
                        std::cin >> dir;
                        purchaseCode = player->buyPotion(dir);
                    }
                    #endif
                } else {
                    std::cin.clear();
                    std::cin.ignore();
                }
                pdebug("Pre DLC");
                #ifdef DLC
                pdebug("DLC defined");
                if (purchaseCode = 1) {
                    std::cout << "Please choose which potion to buy."<< std::endl;
                    std::cout << "Restore health(RH) | Boost Atk (BA) | Boost Def (BD)" << std::endl;
                    while (std::cin >> s) {
                        if (s == "RH") {
                            takePotion("RH");
                            takePotionCode = 1;
                            break;
                        } else if (s == "BA") {
                            takePotion("BA");
                            takePotionCode = 2;
                            break;
                        } else if (s == "BD") {
                            takePotion("BD");
                            takePotionCode = 3;
                            break;
                        } else {
                            std::cout << "Please enter RH|BA|BD to purchase: ";
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                }else if (purchaseCode = 2) {
                    message = "The merchant is not hostile to you."
                }else if (purchaseCode = -1) {
                    message = "No merchant is standing in that direction."
                }
                purchaseCode = 0;
                #endif
                pdebug("DLC not defined");
                
                //Edit Action message
                if (moveRetCode == 1) {
                    pdebug("moveRetCode == 1");
                    message = "You moved your character.";
                    pdebug("mesage edited");
                } else if ( moveRetCode == 2) {
                    message = "You can't walk through walls.";
                } else if (moveRetCode == 3) {
                    message = "You can't walk on an NPC.";
                } else if (moveRetCode == 4) {
                    message = "Gold collected.";
                } else if (moveRetCode == 5) {
                    message = "You have to slain the dragon first.";
                } else if (moveRetCode == 6) {
                    message = "You are standing on an unknown potion.";
                } else if (takePotionCode == 1) {
                    message = "You used an RH potion. health restored by 10.";
                } else if (takePotionCode == 2) {
                    message = "You used a BA potion. ATK boosted by 5.";
                } else if (takePotionCode == 3) {
                    message = "You used a BD potion. DEF boosted by 5.";
                } else if (takePotionCode == 4) {
                    message = "You used a PH potion. health reduced by 10.";
                } else if (takePotionCode == 5) {
                    message = "You used a WA potion. ATK reduced by 5.";
                } else if (takePotionCode == 6) {
                    message = "You used a WD potion. DEF reduced by 5.";
                } else if (takePotionCode == -1) {
                    message = "No potion found.";
                } else if (attackCode == 1) {
                    message = "You defeated an enemy.";
                } else if (attackCode == 2) {
                    message = "You are dead.";
                } else if (attackCode == 3) {
                    message = "Your attack missed.";
                } else if (attackCode == -1) {
                    message = "No enemy found";
                }
                moveRetCode = 0;
                takePotionCode = 0;
                attackCode = 0;
                pdebug("ret codes reset");
                
                if (doMovement) {
                //MOVE ALL ENEMIES
                    pdebug("doMovement true");
                    f[level].npcMove();
                    pdebug("npccs moved");
                }
                
                f[level].printFloor();
                player->printMessage(race,level,message);
                
            }
            
            if (s == "r") {
                break;
            //r to restart the game
            } else if (s == "q") {
                break;
            //q to admit defeat and exit the game
            }
            
            //RESET PLAYER'S ATK AND DEF
            player->reset();
        }
        
            
        if (s == "q") {
            score = player->getScore();
            break;
        } else if (s == "r") {
            std::cout << "Game restarted." << std::endl;
        }
    }
    
    
    std::cout << "Game over. Your score is: " << score << std::endl;
    
}

