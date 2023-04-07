#pragma once
#inclide "Device.h"

class gateOR : public Device {
private:
  int inputVal = 0;   // this value might not be inputed
public:
  gateOR(int iVal = 0): inputVal(iVal) {};

  int getOutput() const override {
    int output = this->inputVal;
    for auto dev in iPins:
      output |= dev.getOutput();
    return output;
  }
};
