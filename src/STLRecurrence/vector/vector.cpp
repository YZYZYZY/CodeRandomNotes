#include "Vector.h"
#include <iostream>
using namespace stl;

int main(){
    //但是这边为什么又识别不出来？因为没加命名空间stl
    Vector<int> a;
    a.at(1) = 1; //为什么会out_of_range？如何对成员变量进行合理的初始化？

    std::cout << a[1];




    return 0;
}