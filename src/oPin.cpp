#include "oPin.h"

#include <string>

using std::string;

void oPin::setGate(Device *gate) {
  this->gate = gate;
}

void oPin::setCircuitOPinFalse() {
  circuitOPin = false;
}

bool oPin::isCircuitOutput() {
  return circuitOPin;
}

Device* oPin::getGate() {
  return gate;
}

// ******************* overrided members ***********************

int oPin::getOutput() {
  return gate->getOutput();  // the oPins only connect to one gate
}

string oPin::getType() {
  return gate->getType();
}
