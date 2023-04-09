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

typedef vector<vector<int>> vvi;

using namespace std;

class LogicSimulator {
private:
  vector<Device *> circuit;
  vector<iPin *> iPins;
  vector<oPin *> oPins;
  vector<

  vector<int> simulationValues;
  string simulationResult;
  string truthTable;
  bool is_loaded = false;

  void setTruthTableValue(vvi &input, vvi &output, int combiations);
  void drawTruthTable(vvi &input, vvi& output, int combiations);

  void runSimulation();
  void drawSimulationTable();

public:
  // simulation
  string getSimulationResult();
  void setSimulationResult();

  // truth table
  string getTruthTable();
  void setTruthTable();

  string getLayout();

  // load
  bool load(string filename);
  void setloaded();
  bool isLoaded();

  // size
  int getIPinSize();
  int getOPinSize();

  // values
  void setIPinsValue(int index, int value);
  int getIPinsValue(int index);
};
