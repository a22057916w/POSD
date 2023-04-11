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
  virtual int getOutput() const = 0;
  virtual string getType() const = 0;
};
