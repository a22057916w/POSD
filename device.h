#pragma once
#include <vector>
using namespace std;

class Device {
protected:
  vector<device *> iPins;
public:
  void addInputPin(device *d);
  void getOutput(); // tmp-def
}
