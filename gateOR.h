#pragma once
#include "Device.h"
#include <string>

class gateOR : public Device {
public:
  gateOR() {};

  int getOutput() const override {
    int output = 0;
    // cout << "gateOR:" << endl;
    for(auto dev : iPins) {
      output |= dev->getOutput();
    }
    // cout << "output: " << output << endl;
    // cout << "~gateOR:" << endl;
    return output;
  }

  string getType() const override {
    return "gateOR";
  }

};
