#pragma once
#inclide "Device.h"

class gateAND : public Device {
public:
  gateAND() {};

  int getOutput() const override {
    int output = 1;
    for auto dev in iPins:
      output &= dev.getOutput();
    return output;
  }
};
