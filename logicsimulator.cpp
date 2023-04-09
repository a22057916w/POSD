#include "logicsimulator.h"

#include <iostream>
#include <string>
#include <cmath>

#include "Device.h"
#include "gateAND.h"
#include "gateNOT.h"
#include "gateOR.h"
#include "iPin.h"
#include "oPin.h"

using namespace std;

string LogicSimulator::getSimulationResult() {    // need to print table !!!
  string result = "";

  for(auto oPin : oPins)
    if(oPin->isCircuitOutput()) {
      cout << oPin->getOutput() << endl;
      result += to_string(oPin->getOutput()) + " ";
    }

  return result;
}


string LogicSimulator::getLayout() {
  int circuitOut = 0;
  for(auto oPin : oPins)
    if(oPin->isCircuitOutput())
      circuitOut++;

  cout << "Circuit: " << iPins.size() << " input pins, "
    << circuitOut << " output pins and "
    << oPins.size() << " gates\n";
}

string LogicSimulator::getTruthTable() {
  cout << "getTruthTable" << endl;
  // calculate the combinations of all input by binary
  int base = 2;
  int exponent = iPins.size();
  int num_combinations = pow(base, exponent);

  int binary_num = 0b0;

  vector<vector<int>> iPin_value;
  vector<vector<int>> oPin_value;

  int iPinSize = iPins.size();
  cout << "iPins Size: " << iPins.size() << endl;

  while(num_combinations--) {
    cout << "binary number: " << binary_num << endl;
    int binary_temp = binary_num;


    for(int i = iPins.size() - 1; i >= 0; i--) {
      int least_bit = binary_temp & 0b1;
      cout << "i: " << i << " binary_temp: " << binary_temp << " least_bit: " << least_bit << endl;
      iPins[i]->setVal(least_bit);
      iPin_value.push_back()
      binary_temp >>= 1;
    }

    cout << "print iPins:" << endl;
    for(int i = 0; i < iPins.size(); i++) {
      cout << "i: " << i << " iPins: ";
      cout << iPins[i]->getOutput() << endl;
    }
    cout << endl;

    string output = getSimulationResult();
    cout << "oPin: " + output << endl;

    binary_num++;   // increase the nuumber to 2^x-1
  }

  cout << "~getTruthTable" << endl;
}

bool LogicSimulator::load(string filename) {
  ifstream file(filename);
  if(!file.good()) {
   return false;
  }

  int iPin_size, gates;
  cin >> iPin_size;
  cin >> gates;

  iPins.resize(iPin_size);
  oPins.resize(gates);

  // can't initial vector of pointers using resize()
  for(int i = 0; i < iPins.size(); i++)
    iPins[i] = new iPin();

  for(int i = 0; i < oPins.size(); i++)
    oPins[i] = new oPin();

  for(int i = 0; i < oPins.size(); i++) {
    cout << oPins.size() << endl;
    int gate_type;
    cin >> gate_type;

    if(gate_type == 1)
      oPins[i]->addGate(new gateAND());
    else if(gate_type == 2)
      oPins[i]->addGate(new gateOR());
    else if(gate_type == 3)
      oPins[i]->addGate(new gateNOT());
    else
      return false;


    double input_pin;
    while(cin >> input_pin && input_pin != 0) {
      if(input_pin < 0) {       // need to review !!!
        int index = abs(int(input_pin)) - 1;
        oPins[i]->getGate()->addInputPin(iPins[index]);  // may out of range
      }
      else {    // need to review !!!
        int index = (int(input_pin) % 10000) - 1;
        oPins[i]->getGate()->addInputPin(oPins[index]);  // need to review
        oPins[index]->setCircuitOPinFalse();
      }
    }
  }

  for(int i = 0; i < iPins.size(); i++)
    cout << i << ": " << iPins[i]->getType() << endl;

  for(int i = 0; i < oPins.size(); i++)
    cout << i << ": " << oPins[i]->getType() << endl;

  return true;
}

void LogicSimulator::setloaded() {
  is_loaded = true;
}

bool LogicSimulator::isLoaded() {
  return is_loaded;
}

int LogicSimulator::getIPinSize() {
  return iPins.size();
}

int LogicSimulator::getOPinSize() {
  return oPins.size();
}

void LogicSimulator::setIPinsValue(int index, int value) {
  iPins[index]->setVal(value);
}

int LogicSimulator::getIPinsValue(int index) {
  return iPins[index]->getOutput();
}
