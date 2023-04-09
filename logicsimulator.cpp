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

vector<int> LogicSimulator::getSimulationResult() {
  vector<int> result;
  for(auto oPin : oPins)
    if(oPin->isCircuitOutput())
      result.push_back(oPin->getOutput());
  return result;
}

// string LogicSimulator::getSimulationResult() {    // need to print table !!!
//   string result = "";
//
//   for(auto oPin : oPins)
//     if(oPin->isCircuitOutput()) {
//       cout << oPin->getOutput() << endl;
//       result += " " + to_string(oPin->getOutput());
//     }
//
//   return result;
// }


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
  // calculate the combinations of all input by binary
  int base = 2;
  int exponent = iPins.size();
  int num_combinations = pow(base, exponent);

  int num = 0b0;

  vector<vector<int>> iPin_table(num_combinations);
  vector<vector<int>> oPin_table(num_combinations);

  while(num < num_combinations) {
    cout << "binary number: " << num << endl;
    int temp = num;


    for(int i = iPins.size() - 1; i >= 0; i--) {
      int least_bit = temp & 0b1;
      cout << "i: " << i << " temp: " << temp << " least_bit: " << least_bit << endl;
      iPins[i]->setVal(least_bit);
      temp >>= 1;
    }

    cout << "print iPins:" << endl;
    for(int i = 0; i < iPins.size(); i++) {
      cout << "i: " << i << " iPins: ";
      cout << iPins[i]->getOutput() << endl;
    }
    cout << endl;

    vector<int> output = getSimulationResult();
    oPin_table[num] = output;

    for(int i = 0; i < iPins.size(); i++)
      iPin_table[num].push_back(iPins[i]->getOutput());

    num++;   // increase the nuumber to 2^x-1
  }


  string table = "";

  int iCol = iPin_table[0].size();
  int oCol = oPin_table[0].size();

  // print i i i i .... | o o o....
  for(int i = 0; i < iCol; i++)
    table += "i ";
  table += "|";
  for(int i = 0; i < oCol; i++)
    table += " o";
  table += "\n";

  // print 1 2 3 4... | 1 2 3 ...
  for(int i = 0; i < iCol; i++)
    table += to_string(i+1) + " ";
  table += "|";
  for(int i = 0; i < oCol; i++)
    table += " " + to_string(i+1);
  table += "\n";

  // print ------+---
  for(int i = 0; i < iCol; i++)
    table += "--";
  table += "+";
  for(int i = 0; i < oCol; i++)
    table += "--";
  table += "\n";

  int row = 0;
  // print truth value
  while(row < num_combinations) {
    for(int col = 0; col < iCol; col++)
      table += to_string(iPin_table[row][col]) + " ";
    table += "|";
    for(int col = 0; col < oCol; col++)
      table += " " + to_string(oPin_table[row][col]);
    table += "\n";

    row++;
  }

  return table;
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
