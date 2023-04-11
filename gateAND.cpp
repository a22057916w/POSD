#include "gateAND.h"

#include <string>

using std::string;

int gateAND::getOutput() {
  int output = 1;
  for(auto dev : iPins)
    output &= dev->getOutput();

  return output;
}

string gateAND::getType() {
  return "gateAND";
}
