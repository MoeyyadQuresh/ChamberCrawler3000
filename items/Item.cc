#include "Item.h"

Item::Item():
  tilePtr{nullptr} {}

Item::Item(Tile* ptr):
  tilePtr{ptr} {}
