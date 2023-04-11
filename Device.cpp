#include "Device.h"

#include <vector>

using namespace std;

void Device::addInputPin(Device *inputPin) {
  iPins.push_back(inputPin);
}
