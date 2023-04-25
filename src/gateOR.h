#pragma once

#include "Device.h"
#include <string>

using std::string;

class gateOR : public Device {
public:
  gateOR() {};

  int getOutput() override;
  string getType() override;
};
