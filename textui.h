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
  }
  void processCommand() {
    int command = -1;
    while(cin >> command && command != 4) {
      string filename;

      switch(command) {
        case 1:
          cout << "Command:1" << endl;

          cout << "Please key in a file path:" << endl;
          cin >> filename;

          if(LS_ptr->load(filename))
            cout << "tmp" << endl;
          else
            cout << "File not found or file format error!!" << endl;
          break;
        case 2:
          cout << "Command:2" << endl;
          break;
        case 3:
          cout << "Command:3" << endl;
          break;
        case 4:
          cout << "Command:4" << endl;
          break;
        default:
          cout << "Invalid command." << endl;
          break;
      }
  }

  }
};
