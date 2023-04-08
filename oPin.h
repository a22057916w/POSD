#pragma once
#include "Device.h"

class oPin : public Device {
private:
  bool circuitOPin = true;
  Device *gate;
public:
  oPin(Device *_gate): gate(_gate) {};

  int getOutput() const override {
    return gate->getOutput();  // the iPins only connect to one gate
  }

  void setCircuitOPin() {
    circuitOPin = false;
  }

  bool isCircuitOutput() {
    return circuitOPin;
  }
};
