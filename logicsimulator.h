#pragma once

#include "iPin.h"
#include "oPin.h"

#include <vector>
#include <string>

typedef vector<vector<int>> vvi;

using namespace std;

class LogicSimulator {
private:
  vector<iPin *> iPins;
  vector<oPin *> oPins;

  bool is_loaded = false;
  string circutLayout;

  vector<int> simulationValues;
  string simulationResult;

  string truthTable;

  // called by load
  void setCircuitLayout();
  void setLoaded();

  // called by setTruthTable
  void setTruthTableValue(vvi &input, vvi &output, int combiations);
  void drawTruthTable(vvi &input, vvi& output, int combiations);

  // called by setSimulationResult
  void runSimulation();
  void drawSimulationTable();

public:
  // load
  bool load(string filename);
  inline bool isLoaded() { return is_loaded; };
  inline string getCircuitLayout() { return circutLayout; };

  // simulation
  void setSimulationResult();
  inline string getSimulationResult() { return simulationResult; };

  // truth table
  void setTruthTable();
  inline string getTruthTable() { return truthTable; };

  // size
  inline int getIPinSize() { return iPins.size(); };
  inline int getOPinSize() { return oPins.size(); };

  // values
  void setIPinsValue(int index, int value);
  inline int getIPinsValue(int index) { return iPins[index]->getOutput(); };
};
