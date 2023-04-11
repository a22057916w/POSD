#pragma once
#include "Device.h"

#include <string>

using std::string;

class oPin : public Device {
private:
  bool circuitOPin = true;
  Device *gate = NULL;
public:
  oPin() {};

  void addGate(Device *gate);
  void setCircuitOPinFalse();
  bool isCircuitOutput();
  Device* getGate();

  int getOutput() override;
  string getType() override;


};
