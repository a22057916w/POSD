#include "Util.h"

#include <string>

using std::string;

template <typename T>
int Util<T>::stoi(string s) {
  size_t pos;
  float val = std::stoi(s, &pos);
  if(pos < s.size())
    throw std::invalid_argument("string contain non-digital characte");

  return val;
}

template <typename T>
float Util<T>::stof(string s) {
  size_t pos;
  float val = std::stof(s, &pos);  // set to float
  if(pos < s.size())
    throw std::invalid_argument("string contain non-digital characte");

  return val;
}

template <typename T>
void Util<T>::clearVectorPointer(vector<T*> &v) {
  for(auto ptr : v)
    delete ptr;
  v.clear();
}
