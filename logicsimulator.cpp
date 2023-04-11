#include "logicsimulator.h"

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>


#include "gateAND.h"
#include "gateNOT.h"
#include "gateOR.h"

using namespace std;


void LogicSimulator::setTruthTableValue(vvi &input_table, vvi &output_table, int num_comb) {
  int input_size = getIPinSize();
  int num_bit = 0b0;               // 0 to 2^n - 1, n = exponent

  // using bitmap to iPins stated with 0000...0000(max: 16 bits)
  while(num_bit < num_comb) {
    int temp_bit = num_bit;

    for(int i = input_size - 1; i >= 0; i--) {
      int least_bit = temp_bit & 0b1;
      this->iPins[i]->setVal(least_bit);
      temp_bit >>= 1;
    }

    int row = num_bit;  //  total rows = num_comb - 1, started with 0

    runSimulation();   // run the simulation to set simulationValues

    vector<int> outputs = this->simulationValues;
    output_table.push_back(outputs);

    vector<int> inputs;
    for(int i = 0; i < input_size; i++)
      inputs.push_back(this->iPins[i]->getOutput());
    input_table.push_back(inputs);

    num_bit++;   // increase the nuumber to 2^n-1
  }
}

void LogicSimulator::drawTruthTable(vvi &input_table, vvi &output_table, int num_comb) {
  string table = "";

  // input/output table has same column numbers in every row;
  int input_col = input_table[0].size();
  int output_col = output_table[0].size();

  // print i i i i .... | o o o....
  for(int i = 0; i < input_col; i++)
    table += "i ";
  table += "|";
  for(int i = 0; i < output_col; i++)
    table += " o";
  table += "\n";

  // print 1 2 3 4... | 1 2 3 ...
  for(int i = 0; i < input_col; i++)
    table += to_string(i+1) + " ";
  table += "|";
  for(int i = 0; i < output_col; i++)
    table += " " + to_string(i+1);
  table += "\n";

  // print ------+---
  for(int i = 0; i < input_col; i++)
    table += "--";
  table += "+";
  for(int i = 0; i < output_col; i++)
    table += "--";
  table += "\n";

  // draw the rest of truth value
  int row = 0;
  while(row < num_comb) {
    for(int col = 0; col < input_col; col++)
      table += to_string(input_table[row][col]) + " ";
    table += "|";
    for(int col = 0; col < output_col; col++)
      table += " " + to_string(output_table[row][col]);
    table += "\n";

    row++;
  }

  this->truthTable = table;
}


void LogicSimulator::drawSimulationTable() {
  string table = "";

  // input/output table has same column numbers in every row;
  int input_col = getIPinSize();
  int output_col = this->simulationValues.size();

  // print i i i i .... | o o o....
  for(int i = 0; i < input_col; i++)
    table += "i ";
  table += "|";
  for(int i = 0; i < output_col; i++)
    table += " o";
  table += "\n";

  // print 1 2 3 4... | 1 2 3 ...
  for(int i = 0; i < input_col; i++)
    table += to_string(i+1) + " ";
  table += "|";
  for(int i = 0; i < output_col; i++)
    table += " " + to_string(i+1);
  table += "\n";

  // print ------+---
  for(int i = 0; i < input_col; i++)
    table += "--";
  table += "+";
  for(int i = 0; i < output_col; i++)
    table += "--";
  table += "\n";

  // print the simulation result
  for(auto iPin : this->iPins)
    table += to_string(iPin->getOutput()) + " ";
  table += "|";
  for(int output : this->simulationValues)
    table += " " + to_string(output);
  table += "\n";

  this->simulationResult = table;
}

// *********************** public method ****************************

void LogicSimulator::runSimulation() {
  vector<int> values;
  for(auto oPin : oPins)
    if(oPin->isCircuitOutput())
      values.push_back(oPin->getOutput());
  this->simulationValues = values;
}

void LogicSimulator::setSimulationResult() {
  runSimulation();
  drawSimulationTable();
}

string LogicSimulator::getSimulationResult() {    // need to print table !!!
  return simulationResult;
}

string LogicSimulator::getLayout() {
  int circuitOut = 0;
  for(auto oPin : oPins)
    if(oPin->isCircuitOutput())
      circuitOut++;
  string layout = "";
  layout += "Circuit: " + to_string(iPins.size()) + " input pins, " + to_string(circuitOut)
    + " output pins and " + to_string(oPins.size()) + " gates\n";

  return layout;
}

string LogicSimulator::getTruthTable() {
  return truthTable;
}

void LogicSimulator::setTruthTable() {

  // calculate the combinations of all input by binary
  int base = 2;
  int exponent = getIPinSize();
  int num_comb = pow(base, exponent);

  // store all input combiations and output's
  vvi input_table;
  vvi output_table;

  // set value to input/output table
  this->setTruthTableValue(input_table, output_table, num_comb);
  // set truthTable by input/output table
  this->drawTruthTable(input_table, output_table, num_comb);
}

bool LogicSimulator::load(string filename) {
  ifstream fin(filename, std::ios::in);

  // if file is not open corretly, return false
  if(!fin.is_open())
    return false;

  int iPin_size, gates;
  fin >> iPin_size;
  fin >> gates;

  // resize vector size by inputs
  iPins.resize(iPin_size);
  oPins.resize(gates);

  // can't initial vector of pointers using resize()
  for(int i = 0; i < iPins.size(); i++)
    iPins[i] = new iPin();
  for(int i = 0; i < oPins.size(); i++)
    oPins[i] = new oPin();

  // read gates and it's connections
  for(int i = 0; i < oPins.size(); i++) {
    int gate_type;
    fin >> gate_type;

    // read gate type
    if(gate_type == 1)
      oPins[i]->setGate(new gateAND());
    else if(gate_type == 2)
      oPins[i]->setGate(new gateOR());
    else if(gate_type == 3)
      oPins[i]->setGate(new gateNOT());
    else
      return false; // if gate type is wrong, return false

    // read connections
    double input_pin;
    while(fin >> input_pin && input_pin != 0) {
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
  fin.close();

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
