#include "PlayerExclusive.h"

bool PlayerExclusive::passable(const Character& c) const noexcept {
  return c.isPlayer;
}
