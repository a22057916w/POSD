#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename T>
class Util {
public:
  static int stoi(string s);
  static float stof(string s);

  static void clearVectorPointer(vector<T*> &v);
};
