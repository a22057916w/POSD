#pragma once

#include "Device.h"
#include "iPin.h"
#include "oPin.h"

#include <vector>
#include <string>

typedef vector<vector<int>> vvi;

using namespace std;

class LogicSimulator {
private:
  vector<Device *> circuit;
  vector<iPin *> iPins;
  vector<oPin *> oPins;

  vector<int> simulationValues;
  string simulationResult;
  string truthTable;
  bool is_loaded = false;

  // called by setTruthTable
  void setTruthTableValue(vvi &input, vvi &output, int combiations);
  void drawTruthTable(vvi &input, vvi& output, int combiations);

  // called by setSimulationResult
  void runSimulation();
  void drawSimulationTable();

public:
  // simulation
  void setSimulationResult();
  string getSimulationResult() { return simulationResult; };

  // truth table
  void setTruthTable();
  inline string getTruthTable() { return truthTable; };

  string getLayout();

  // load
  bool load(string filename);
  void setloaded();
  inline bool isLoaded() { return is_loaded; };

  // size
  inline int getIPinSize() { return iPins.size(); };
  inline int getOPinSize() { return oPins.size(); };

  // values
  void setIPinsValue(int index, int value);
  inline int getIPinsValue(int index) { return iPins[index]->getOutput(); };
};
