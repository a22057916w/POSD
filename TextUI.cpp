#include "TextUI.h"

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

void TextUI::loading() {
  string filename;  // path of lcf file

  cout << "Please key in a file path: ";
  cin >> filename;

  if(!LS_ptr->load(filename)) {
    cout << "File not found or file format error!!" << endl;
    return;
  }

  LS_ptr->setloaded();
  LS_ptr->getLayout();

}

void TextUI::readInputPins() {
  if(!LS_ptr->isLoaded()) {
    cout << "Please load an lcf file, before using this operation." << endl;
    return;
  }

  int size = LS_ptr->getIPinSize();

  int i = 0;
  while(i < size) {
    int input_value;

    cout << "Please key in the value of input pin " << i+1 << ": ";
    cin >> input_value;

    if(input_value != 0 && input_value != 1) {
      cout << "The value of input pin must be 0/1" << endl;
      continue;
    }

    LS_ptr->setIPinsValue(i, input_value);
    i++;
  }
}
