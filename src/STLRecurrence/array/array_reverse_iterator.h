#pragma once

// 不同文件中的命名空间可以一样吗？命名空间和引用头文件的关系是什么呢？
namespace stl
{
    template <typename T>
    class ArrayReverseIterator
    {
        typedef ArrayReverseIterator<T> iterator; // 类型别名
    public:
        // 代码量少，可以声明和实现写在一起
        ArrayReverseIterator() : m_pointer(nullptr) {}
        ArrayReverseIterator(T *pointer) : m_pointer(pointer) {}
        ~ArrayReverseIterator() {}

        bool operator==(const iterator &other) const
        {
            return m_pointer == other.m_pointer; // 是指针相等
        }

        bool operator!=(const iterator &other) const
        {
            return m_pointer != other.m_pointer;
        }

        iterator &operator=(const iterator &other)
        {
            if (this == &other)
                return *this; // 返回的是地址，为什么要解指针？
            m_pointer = other.m_pointer;
            return *this; // 这里没懂
        }

        // 前缀++
        iterator &operator++() 
        {
            m_pointer -= 1;
            return *this;
        }

        // 后缀++
        iterator operator++(int) // 为什么这还必须要这个参数int？只有类型名，没有形参名？
        {
            iterator it = *this;
            ++(*this); //这里的++，使用的就是前面重载过后的++
            return it; // 返回的是临时变量迭代器
        }

        iterator operator+(int n)
        {
            iterator it = *this;
            it.m_pointer -= n;
            return it;
        }

        iterator &operator+=(int n)
        {
            m_pointer -= n; // 写成this.m_pointer += n; 也是一样的？
            return *this;   // 对本身有影响
        }

        // 前缀--
        iterator &operator--()
        {
            m_pointer += 1;
            return *this;
        }

        // 后缀--
        iterator operator--(int) // 为什么这还必须要这个参数int？只有类型名，没有形参名？
        {
            iterator it = *this;
            --(*this);
            return it; // 返回的是临时变量迭代器
        }

        iterator operator-(int n)
        {
            iterator it = *this;
            it.m_pointer += n; // 这里使用到的和下面定义的有什么区别吗？
            return it;
        }

        iterator &operator-=(int n)
        {
            m_pointer += n; // 写成this.m_pointer += n; 也是一样的？
            return *this;   // 对本身有影响
        }

        // 两个迭代器相减，得到它们之间的距离
        int operator-(const iterator &other) const
        {
            return m_pointer - other.m_pointer;
        }

        // 实现解引用 就是这些左值引用加的感觉莫名奇妙的，哪些情况下会加？
        T &operator*()
        {
            return *m_pointer;
        }

        T *operator->()
        {
            return m_pointer;
            // return &(operator*()); //第二种写法
        }

    private:
        T *m_pointer; // 通过指针指向数组的对应位置
    };

}