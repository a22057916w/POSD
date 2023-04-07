#include "logicsimulator.h"
#include "textui.h"
#include <iostream>

int main() {
  LogicSimulator *LS = new LogicSimulator();
  TextUI textUI(LS);
  textUI.displayMenu();
  textUI.processCommand();
  return 0;
}
