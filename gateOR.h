#pragma once
#include "Device.h"

class gateOR : public Device {
public:
  gateOR() {};

  int getOutput() const override {
    int output = 0;
    for(auto dev : iPins)
      output |= dev->getOutput();
    return output;
  }
};
