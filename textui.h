#pragma once
#include "Logicsimulator.h"
#include <iostream>
#include <string>
using namespace std;

class TextUI {
private:
  LogicSimulator *LS;
public:
  TextUI(LogicSimulator *_LS): LS(_LS) {};

  void displayMenu();
  void processCommand();

  // for processCommand()
  void loading();
  void readInputPins();
  void displayTruthTable();
  void Exit();
};
