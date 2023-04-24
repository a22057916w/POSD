#include "..\LogicSimulator.h"

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>

#include "..\GateAND.h"
#include "..\GateNOT.h"
#include "..\GateOR.h"
#include "..\iPin.h"
#include "..\oPin.h"

typedef vector<vector<int>> vvi;

using namespace std;

void testLogicSimulator() {
  // Create input pins
  IPin *a = new IPin();
  IPin *b = new IPin();
  IPin *c = new IPin();

  // Create gates
  GateAND *and1 = new GateAND(a, b);
  GateNOT *not1 = new GateNOT(and1->getOutput());
  GateOR *or1 = new GateOR(not1->getOutput(), c);

  // Create output pins
  OPin *out = new OPin(or1->getOutput());

  // Create a logic simulator
  LogicSimulator sim;
  sim.addIPin(a);
  sim.addIPin(b);
  sim.addIPin(c);
  sim.addOPin(out);

  // Set the circuit layout
  sim.setCircuitLayout();
  assert(sim.getCircuitLayout() == "Circuit: 3 input pins, 1 output pins and 3 gates\n");

  // Draw truth table
  vvi input_table;
  vvi output_table;
  sim.setTruthTableValue(input_table, output_table, pow(2, 3));
  sim.drawTruthTable(input_table, output_table, pow(2, 3));
  assert(sim.getTruthTable() == "i i i | o\n------+\n0 0 0 | 1\n0 0 1 | 0\n0 1 0 | 0\n0 1 1 | 1\n1 0 0 | 1\n1 0 1 | 0\n1 1 0 | 1\n1 1 1 | 1\n");

  // Draw simulation table
  sim.runSimulation();
  sim.drawSimulationTable();
  assert(sim.getSimulationTable() == "i i i | o\n------+\n0 0 0 | 1\n");
}

int main() {
  testLogicSimulator();

  cout << "All tests passed!\n";

  return 0;
}
