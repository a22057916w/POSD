#pragma once
#include "Device.h"

class iPin : public Device {
private:
  int inputVal;
public:
  iPin() {};

  int getOutput() const override {
    return inputVal;
  }
}
