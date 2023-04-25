#pragma once

#include <vector>

// clear and relase the memory of vector of pointer
template <typename T>
void Util::clearVectorPointer(std::vector<T*> &v) {
  for(auto ptr : v)
    delete ptr;
  v.clear();
}
