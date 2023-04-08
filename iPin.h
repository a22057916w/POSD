#pragma once
#include "Device.h"
#include <string>

class iPin : public Device {
private:
  int inputVal;
public:
  iPin() {};

  int getOutput() const override {
    return inputVal;
  }

  string getType() const override {
    return "iPin";
  }
};
