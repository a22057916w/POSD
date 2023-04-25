#include "gateNOT.h"

#include <string>

using std::string;

int gateNOT::getOutput() {
  int output;
  for(auto dev : iPins)   // the size of iPins should be one
    output = !dev->getOutput();
  return output;
}

string gateNOT::getType() {
  return "gateNOT";
}
