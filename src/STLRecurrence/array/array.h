#pragma once

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <array_iterator.h>
#include <array_const_iterator.h>
#include <array_reverse_iterator.h>

namespace stl
{
    //
    template <typename T, int N> // 为什么size_t会标红？是路径问题，还是没有编译？
    class Array
    {
    public:
        // 其实头文件已经包含这些类了，可以在Array中定义的想用的类型了。
        typedef ArrayIterator<T> iterator; // 为什么这里也要取别名啊，作用域是怎么样的？还有T怎么传？
        typedef ArrayConstIterator<T> const_iterator;
        typedef ArrayReverseIterator<T> reverse_iterator;

    public:
        Array();
        ~Array();

        int size() const; // const1. 常成员函数,无法修改成员变量,允许这个函数在常量对象上被调用
        bool empty() const;
        T *data();
        const T *data() const;

        void swap(Array<T, N> &other); // 这里的类型声明也要加上<T, N>，可以不加吗？可以不加
        void fill(const T &value);     // const2. 避免了不必要的复制，同时保证函数不会改变输入数据

        T &front(); // 左值引用
        // 这种写法算多态吗？算函数重载 什么时候选择哪个版本？使用的时候如何决定上下文？
        const T &front() const; // const3.第一个表示常量引用 第二个表示常成员函数

        T &back();
        const T &back() const;

        T &at(int index);
        const T &at(int index) const;

        //访问元素
        T &operator[](int index);
        const T &operator[](int index) const;

        void show() const;

        // todo iterator 实现三类迭代器 迭代器可以通过共有方法来访问Array的私有数据成员
        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

    private:         // 只能被类的自身的函数访问
        T m_data[N]; // 所以就是对内置数组的类封装 这里并没有实际分配空间？是通过什么来知道具体空间的？
    };

#include "array.inl"

}