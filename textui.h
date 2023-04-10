#pragma once
#include "Logicsimulator.h"
#include <iostream>
#include <string>
using namespace std;

class TextUI {
private:
  LogicSimulator *LS;

  // for processCommand()
  void loadCircut();
  void readInputPins();
  void displaySimulationResult();
  void displayTruthTable();
  void Exit();

public:
  TextUI(LogicSimulator *_LS): LS(_LS) {};

  void displayMenu();
  void processCommand();
};
