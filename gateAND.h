#pragma once
#include "Device.h"

class gateAND : public Device {
public:
  gateAND() {};

  int getOutput() const override {
    int output = 1;
    for(auto dev : iPins)
      output &= dev->getOutput();
    return output;
  }
};
