#pragma once

#include "LogicSimulator.h"

#include <string>

using namespace std;

class TextUI {
private:
  LogicSimulator *LS;

  // command: 1
  bool loadCircuit();
  void displayCircuit();

  // command: 2
  bool readInputPins();
  void displaySimulationResult();

  // command: 3
  void displayTruthTable();
public:
  TextUI(LogicSimulator *_LS): LS(_LS) {};

  void displayMenu();
  void processCommand();
};
