#include "isDirection.h"

bool isDirection(const std::string& s){
  return (s == "no" ||
          s == "so" ||
          s == "ea" ||
          s == "we" ||
          s == "ne" ||
          s == "nw" ||
          s == "se" ||
          s == "sw");
}
