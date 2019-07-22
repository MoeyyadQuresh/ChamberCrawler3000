#include "Abs.h"

int abs(int x) {
  if (x < 0){
    x *= -1;
  }
  return x;
}
