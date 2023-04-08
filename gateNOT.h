#pragma once
#include "Device.h"

class gateNOT : public Device {
public:
  gateNOT() {};

  int getOutput() const override {
    int output = 0;
    for(auto dev : iPins)  // the size of iPins should be one
      output -= dev->getOutput();
    return output;
  }

  string getType() const override {
    return "gateNOT";
  }
};
