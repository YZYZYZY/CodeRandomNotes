// #include <src/STLRecurrence/array/array.h> //路径需要这么复杂吗？而且这样的路径还要编译错误？
#include "array.h"
using namespace stl;

int main()
{
    Array<int, 10> a; //就是想说这里这个数组a是怎么和类的私有成员变量在地址的角度对上的？m_data只是a这个对象内存中的一部分

    a.fill(1);
    a.show();

    a[0] = 2;
    a.at(2) = 4;

    for (auto it = a.rbegin(); it != a.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    a.show();

    Array<int, 10> b;
    for (int i = 0; i < b.size(); i++)
    {
        b[i] = i;
    }
    for (auto it = b.rbegin(); it != b.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
