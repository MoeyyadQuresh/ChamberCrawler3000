#include "global.h"
#include "Floor.h"
#include "getTile.h"

Tile* getTile(int x, int y){
  return f[level].whichTile(x, y);
}
