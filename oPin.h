#pragma once
#include "Device.h"
#include <string>

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

  string getType() const override {
    return gate->getType();
  }

  void setCircuitOPinFalse() {
    circuitOPin = false;
  }

  bool isCircuitOutput() {
    return circuitOPin;
  }

  Device* getGate() {
    return gate;
  }
};
