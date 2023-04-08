#pragma once
#include "Device.h"

class oPin : public Device {
private:
  bool circuitOPin = true;
  Device *gate = NULL;
public:
  oPin() {};

  void addGate(Device *gate) {
    this->gate = gate;
  }

  int getOutput() const override {
    return gate->getOutput();  // the iPins only connect to one gate
  }

  void setCircuitOPinFalse() {
    circuitOPin = false;
  }

  bool isCircuitOutput() {
    return circuitOPin;
  }
};
