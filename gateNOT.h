#pragma once
#include "Device.h"
#include <string>

class gateNOT : public Device {
public:
  gateNOT() {};

  int getOutput() const override {
    // cout << "gateNOT:" << endl;
    int output;
    for(auto dev : iPins) {   // the size of iPins should be one
      output = !dev->getOutput();
    }
    // cout << "output: " << output << endl;
    // cout << "~gateNOT:" << endl;
    return output;
  }

  string getType() const override {
    return "gateNOT";
  }
};
