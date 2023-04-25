#pragma once

#include "Device.h"
#include <string>

using namespace std;

class gateAND : public Device {
public:
  gateAND() {};

  int getOutput() override;
  string getType() override;
};
