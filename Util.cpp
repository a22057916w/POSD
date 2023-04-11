#include "Util.h"

#include <string>

using std::string;

int Util::stoi(string s) {
  size_t pos;
  float val = std::stoi(s, &pos);
  if(pos < s.size())
    throw std::invalid_argument("string contain non-digital characte");

  return val;
}

float Util::stof(string s) {
  size_t pos;
  float val = std::stof(s, &pos);  // set to float
  if(pos < s.size())
    throw std::invalid_argument("string contain non-digital characte");

  return val;
}
