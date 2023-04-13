#pragma once

#include <iostream>
#include <string>
#include <vector>


class Util {
public:
  static int stoi(std::string s);
  static float stof(std::string s);

  template <typename T>
  static void clearVectorPointer(std::vector<T*> &v);
};

#include "Util.tpp"

// template <typename T>
// void Util::clearVectorPointer(std::vector<T*> &v) {
//   for(auto ptr : v)
//     delete ptr;
//   v.clear();
// }
