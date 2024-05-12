// #include <src/STLRecurrence/array/array.h> //路径需要这么复杂吗？而且这样的路径还要编译错误？
#include "array.h"
using namespace stl;

int main()
{
    Array<int, 10> a;

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
