#include "gateOR.h"

#include <string>

using std::string;

int gateOR::getOutput() {
  int output = 0;
  for(auto dev : iPins)
    output |= dev->getOutput();

  return output;
}

string gateOR::getType() {
  return "gateOR";
}
