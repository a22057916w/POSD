#pragma once

#include <vector>
#include <string>

using namespace std;

class Device {
protected:
  vector<Device *> iPins; // could be pin or gate
public:
  void addInputPin(Device *inputPin);

  // override by gateXXX, iPin, oPin
  virtual int getOutput() = 0;
  virtual string getType() = 0;
};
