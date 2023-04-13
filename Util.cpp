#include "Util.h"

#include <string>
#include <vector>

// handle invalid_argument exception
int Util::stoi(std::string s) {
  size_t pos;
  int val = std::stoi(s, &pos);
  if(pos < s.size())
    throw std::invalid_argument("string contain non-digital characte");

  return val;
}

// handle invalid_argument exception
float Util::stof(std::string s) {
  size_t pos;
  float val = std::stof(s, &pos);
  if(pos < s.size())
    throw std::invalid_argument("string contain non-digital characte");

  return val;
}
