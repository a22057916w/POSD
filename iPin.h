#pragma once
#include "Device.h"
#include <string>

class iPin : public Device {
private:
  int val;
public:
  iPin() {};

  void setVal(int value) {
    val = value;
  }

  int getOutput() const override {
    return val;
  }

  string getType() const override {
    return "iPin";
  }
};
