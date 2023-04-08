#pragma once
#include "Device.h"
#include <string>

class gateOR : public Device {
public:
  gateOR() {};

  int getOutput() const override {
    int output = 0;
    for(auto dev : iPins)
      output |= dev->getOutput();
    return output;
  }

  string getType() const override {
    return "gateOR";
  }

};
