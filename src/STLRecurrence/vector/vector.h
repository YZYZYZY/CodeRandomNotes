#pragma once

#include <stdexcept>

namespace stl
{
    template <typename T> // 官方的不还有一个allocator吗
    class Vector
    {
    public:
        Vector();
        ~Vector();

        // 为什么返回引用，不直接返回地址？地址是什么时候绑定唯一引用的？编译器决定的？
        T &at(int index);
        const T &at(int index) const;

        T &front();
        const T &front() const;
        
        T &back();
        const T &back() const;

        T *data();
        const T *data() const;

        T &operator[](int index);
        const T &operator[](int index) const;

    private:
        T *m_data; // 这里是数组的指针，指向哪个数组？在初始化的时候指向？
        int m_size;
        int m_capacity;
    };

#include "Vector.inl"
}
