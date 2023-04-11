#pragma once

#include "Device.h"
#include <string>

using std::string;

class gateNOT : public Device {
public:
  gateNOT() {};

  int getOutput() override;
  string getType() override;
};
