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

  void displayMenu() {
    cout << "1. Load logic circuit file\n"
      << "2. Simulation\n"
      << "3. Display truth table\n"
      << "4. Exit\n";
    cout << "Command:";
  }
  void processCommand() {
    int command = -1;
    while(cin >> command && command != 4) {
      if(command == 1) {
        string filename;  // path of lcf file

        cout << "Please key in a file path: ";
        cin >> filename;

        if(LS_ptr->load(filename))
          LS_ptr->getLayout();
        else
          cout << "File not found or file format error!!" << endl;
      }
      else if(command == 2) {
        cout << command << endl;
      }
      else if(command == 3) {
        cout << command << endl;
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
};
