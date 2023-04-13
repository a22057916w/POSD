#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void clearVectorPointer(vector<T*> &v) {
  for(auto ptr : v)
    delete ptr;
  v.clear();
}

int main() {
    std::vector<int*> v;  // 创建一个存储指针的 vector

    // 分配一些指针并将它们添加到 vector 中
    int* p1 = new int(1);
    int* p2 = new int(2);
    int* p3 = new int(3);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // // 释放所有指针指向的内存
    // for (auto ptr : v) {
    //     delete ptr;
    // }
    //
    // // 释放 vector 中的所有元素
    // v.clear();
    clearVectorPointer(v);
    cout << v.size() << endl;
    return 0;
}
