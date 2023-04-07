#pragma once
#inclide "Device.h"

class iPin : public Device {
private:
  int inputVal;
  int inputNum;
public:
  iPin(iVal, iNum): inputVal(iVal), inputNum(iNum) {};

  int getOutput() const override {

  }
}
