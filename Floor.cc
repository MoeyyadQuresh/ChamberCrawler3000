#include "Floor.h"
#include <fstream>
#include <cstdlib>
#include "getTile.h"


Floor::Floor(): tiles{new Tile[1975]}, chambers{new Chamber[5]} {
    for (int i = 0; i < 1975; i++) {
        tiles[i].pos.x = i%79;
        tiles[i].pos.y = i/79;
   }
}

Floor::~Floor() {
  delete[] tiles;
  delete[] chambers;
}

void Floor::init() {
    std::ifstream map{"cc3kfloor.txt"};
    char curr_tile;
    int i = 0;
    while (map >> curr_tile) {
        if (curr_tile == '|') {
            tiles[i].background.reset(new VerticalWall);
        } else if (curr_tile == '-') {
            tiles[i].background.reset(new HorizontalWall);
        } else if (curr_tile == '+') {
            tiles[i].background.reset(new Doorway);
        } else if (curr_tile == '#') {
            tiles[i].background.reset(new Passage);
        } else if (curr_tile == '\\') {
            tiles[i].background.reset(new Stair);
        } else if (curr_tile == '0') {
            tiles[i].background.reset(new TheVoid);
        } else if (curr_tile == '1' || curr_tile == '2' || curr_tile == '3' ||
                   curr_tile == '4' || curr_tile == '5') {
            //add this position to its chamber
            chambers[curr_tile - '1'].positions.push_back(Position(i%79, i/79));
            tiles[i].background.reset(new FloorTile);
        }
        i++;
    }
    
    this->SpawnItems();
    this->SpawnEnemies();
}

void Floor::SpawnItems() {
    for (int itemCount = 0; itemCount < 10; ++itemCount){
        int r = rand() % 5;
        int which = rand() % 8;
        Position& p = chambers[r].getRandomPosition();
        
        Tile* tile = getTile(p.x, p.y);
        if (!(tile->item) &&
            !(tile->character) &&
          !(getTile(p.x+1,p.y)->character) &&
          !(getTile(p.x+1,p.y)->item)){
            
          if (which < 5){
            tile->item.reset(new NormalPile(tile));
          } else if (which == 5){
            tile->item.reset(new DragonHoard(tile));
            Tile* dragonTile = getTile(p.x + 1, p.y);
            dragonTile->character.reset(new Dragon(dragonTile, tile->item));
          } else {
            tile->item.reset(new SmallPile(tile));
          }
        }
    }
}

void Floor::SpawnEnemies() {
    int which;
    for (int enemyCount = 0; enemyCount < 20; ++enemyCount){
        int r = rand() % 5;
        int enemy = rand() % 18;
        Position& p = chambers[r].getRandomPosition();
        Tile* tile = getTile(p.x, p.y);
        
        if (!tile->character && !tile->item){
            if (enemy < 4){
                tile->character.reset(new Human(tile));
            } else if (enemy < 7){
                tile->character.reset(new Dwarf(tile));
            } else if (enemy < 12){
                tile->character.reset(new Halfling(tile));
            } else if (enemy < 14){
                tile->character.reset(new Elf(tile));
            } else if (enemy < 16){
                tile->character.reset(new Orc(tile));
            } else {
                tile->character.reset(new Merchant(tile));
            }
            tile->character->tilePtr = tile;
        }
    }
}

void Floor::SpawnPlayer(std::shared_ptr<Player> c) {
    while (1) {
        int r = rand() % 5;
        Position& p = chambers[r].getRandomPosition(); //Take a random position from all floortile
        //std::cout << p.x << ", " << p.y << std::endl;
        Tile* tile = getTile(p.x, p.y);
        if (!tile->character && //no enemy's on this tile
            !tile->item) { //no item's on this tile
            tile->character = c;
            c->tilePtr = tile;
            break;
        }
    }
}

void Floor::printFloor() {
    for (int i = 0; i < 1975; i++) {
        std::cout << "" << tiles[i].getChar() << "";
        if (tiles[i].getX() == 78){
          std::cout << "" << std::endl << "";
        }
    }
}

void Floor::npcMove() {
    for( int i = 0; i < 1975; i++) {
        tiles[i].update();
    }
}

Tile* Floor::whichTile(int x, int y){
    return &(tiles[y*79 + x]);
}
