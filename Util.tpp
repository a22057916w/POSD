#pragma once

#include <vector>

template <typename T>
void Util::clearVectorPointer(std::vector<T*> &v) {
  for(auto ptr : v)
    delete ptr;
  v.clear();
}
