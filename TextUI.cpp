#include "TextUI.h"

#include <iostream>
#include <cstdio>

using namespace std;

void TextUI::displayMenu() {
  cout << "1. Load logic circuit file\n"
    << "2. Simulation\n"
    << "3. Display truth table\n"
    << "4. Exit\n";
  cout << "Command:";
}

void TextUI::processCommand() {
  string command = "";
  while(cin >> command && command != "4") {
    if(command == "1") {
      if(loadCircuit())
        displayCircuit();
    }
    else if(command == "2") {
      if(readInputPins())
        displaySimulationResult();
    }
    else if(command == "3") {
      displayTruthTable();
    }
    else if(command == "4") {
      cout << "Goodbye, thanks for using LS." << endl;
      break;
    }
    else
        cout << "Invalid command." << endl;

    displayMenu();
  }
}

// ************************ private members ********************
// command 1
bool TextUI::loadCircuit() {
  string filename;  // path of lcf file

  cout << "Please key in a file path: ";
  cin >> filename;

  if(!LS->load(filename)) {
    cout << "File not found or file format error!!" << endl;
    return false;
  }

  return true;
}

void TextUI::displayCircuit() {
  printf("%s\n", LS->getCircuitLayout().c_str());
}

// command 2
bool TextUI::readInputPins() {
  if(!LS->isLoaded()) {
    cout << "Please load an lcf file, before using this operation." << endl;
    return false;
  }

  // get the number of inputs
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

  return true;
}

// command 2
void TextUI::displaySimulationResult() {
  LS->setSimulationResult();
  printf("%s\n", LS->getSimulationResult().c_str());
}

// command 3
void TextUI::displayTruthTable() {
  if(!LS->isLoaded()) {
      cout << "Please load an lcf file, before using this operation." << endl;
      return;
  }

  LS->calTruthTable();  // calaulate the truth table
  printf("%s\n", LS->getTruthTable().c_str());
}
