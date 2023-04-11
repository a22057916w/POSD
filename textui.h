#pragma once

#include "Logicsimulator.h"

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
  void Exit();

public:
  TextUI(LogicSimulator *_LS): LS(_LS) {};

  void displayMenu();
  void processCommand();
};
