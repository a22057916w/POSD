#pragma once

#include "Device.h"
#include <string>

using std::string;

class iPin : public Device {
private:
  int value;
public:
  iPin() {};

  void setVal(int value);

  int getOutput() override;
  string getType() override;
};
