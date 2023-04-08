#pragma once
#include "Logicsimulator.h"
#include <iostream>
#include <string>
using namespace std;

class TextUI {
private:
  LogicSimulator *LS_ptr;
public:
  TextUI(LogicSimulator *LS): LS_ptr(LS) {};

  void displayMenu();
  void processCommand();

  // for processCommand()
  void loading();
  void readInputPins();
  void displayTruthTable();
  void Exit();
};
