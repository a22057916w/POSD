#include "logicsimulator.h"

#include <iostream>
#include <string>

#include "Device.h"
#include "gateAND.h"
#include "gateNOT.h"
#include "gateOR.h"
#include "iPin.h"
#include "oPin.h"

using namespace std;

string LogicSimulator::getLayout() {
  int circuitOut = 0;
  for(auto oPin : oPins)
    if(oPin->isCircuitOutput())
      circuitOut++;

  cout << "Circuit: " << iPins.size() << " input pins, "
    << circuitOut << " output pins and "
    << oPins.size() << " gates\n";
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
        iPins[index] = new iPin();  // may out of range
        oPins[i]->addInputPin(iPins[index]);
      }
      else {    // need to review !!!
        int index = (int(input_pin) % 10000) - 1;
        oPins[i]->addInputPin(oPins[index]);
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
