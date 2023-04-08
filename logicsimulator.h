#pragma once

#include "Device.h"
#include "gateAND.h"
#include "gateNOT.h"
#include "gateOR.h"
#include "iPin.h"
#include "oPin.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class LogicSimulator {
private:
  vector<Device *> circuit;
  vector<Device *> iPins;
  vector<oPin *> oPins;
public:
  string getSimulationResult(vector<string> v_tmp);
  string getTruthTable();
  string getLayout();
  
  bool load(string filename);
  bool isLoaded();
};
