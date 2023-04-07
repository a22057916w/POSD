#pragma once
#include <vector>
using namespace std;

class Device {
protected:
  int inputNum;   // could be pin number or gate number
  int inputType;
  vector<Device *> iPins;
public:
  Device(int _inputNum, int _inputType): inputNum(inputNum), inputType(_inputType) {};
  void addInputPin(Device *inputPin) {
    iPins.append(inputPin);
  }
  virtual int getOutput() = 0; // tmp-def
}
