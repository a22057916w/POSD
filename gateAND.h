#pragma once
#inclide "Device.h"

class gateAND : public Device {
public:
  gateAND(int _inputNum, int _inputType): Device(_inputNum, _inputType) {};
};
