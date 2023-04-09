#pragma once
#include "Device.h"
#include <string>

class gateAND : public Device {
public:
  gateAND() {};

  int getOutput() const override {
    int output = 1;
    // cout << "gateAND:" << endl;
    for(auto dev : iPins) {
      output &= dev->getOutput();
    }
    // cout << "output: " << output << endl;
    // cout << "~gateAND:" << endl;
    return output;
  }

  string getType() const override {
    return "gateAND";
  }
};
