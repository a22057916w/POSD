#pargma once
#include "device.h"
#include <vector>
#include <string>
using namespace std;

class LogicSimulator {
private:
  vector<device *> circuit;
  vector<device *> iPins;
  vector<device *> oPins;
public:
  string getSimulationResult(vector<string> v_tmp);
  string getTruthTable();
  bool load(string s);
}
