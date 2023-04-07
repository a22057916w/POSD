#pragma once
#inclide "Device.h"

class gateAND : public Device {
public:
  gateAND(int _inputNum, int _inputType): Device(_inputNum, _inputType) {};

  int getOutput() const override {
    int output = 1;
    for const auto &dev in iPins:
      output &= dev.getOutput();
    return output;
  }
};
