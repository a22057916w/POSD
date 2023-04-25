#include "iPin.h"

#include <string>

using std::string;

void iPin::setVal(int value) {
  this->value = value;
}

// *************** overrided members *******************

int iPin::getOutput() {
  return value;
}

string iPin::getType() {
  return "iPin";
}
