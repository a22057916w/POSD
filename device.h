#pragma once
#include <vector>
using namespace std;

class Device {
protected:
  vector<Device *> iPins; // could be pin or gate

public:
  void addInputPin(Device *inputPin) {
    iPins.push_back(inputPin);
  }
  virtual int getOutput() const = 0; // tmp-def
}
