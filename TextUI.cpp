#include "TextUI.h"

#include <cmath>

using namespace std;

void TextUI::displayMenu() {
  cout << "1. Load logic circuit file\n"
    << "2. Simulation\n"
    << "3. Display truth table\n"
    << "4. Exit\n";
  cout << "Command:";
}

void TextUI::processCommand() {
  int command = -1;
  while(cin >> command && command != 4) {
    if(command == 1) {
      loading();
    }
    else if(command == 2) {
      readInputPins();
      LS->getSimulationResult();
    }
    else if(command == 3) {
      displayTruthTable();
    }
    else if(command == 4) {
      cout << "Goodbye, thanks for using LS." << endl;
      break;
    }
    else
        cout << "Invalid command." << endl;

    displayMenu();
  }
}

void TextUI::loading() {
  string filename;  // path of lcf file

  cout << "Please key in a file path: ";
  cin >> filename;

  if(!LS->load(filename)) {
    cout << "File not found or file format error!!" << endl;
    return;
  }

  LS->setloaded();
  LS->getLayout();

}

void TextUI::readInputPins() {
  if(!LS->isLoaded()) {
    cout << "Please load an lcf file, before using this operation." << endl;
    return;
  }

  int size = LS->getIPinSize();

  int i = 0;
  while(i < size) {
    int input_value;

    cout << "Please key in the value of input pin " << i+1 << ": ";
    cin >> input_value;

    if(input_value != 0 && input_value != 1) {
      cout << "The value of input pin must be 0/1" << endl;
      continue;
    }

    LS->setIPinsValue(i, input_value);
    i++;
  }
}

void TextUI::displayTruthTable() {
  if(!LS->isLoaded()) {
      cout << "Please load an lcf file, before using this operation." << endl;
      return;
  }
  
  LS->setTruthTable();
  string truthTable = LS->getTruthTable();
  cout << truthTable << endl;
}
