//.inl表示内联函数源文件 和.cpp文件有本质区别，不会被编译成.o文件，编译的时候会与头文件整合到一起。
// 模板类声明和实现要放在一个文件里面，不能分开。只是从我们开发人员的角度看是分开了。
// 要不要包含这个头文件。不包含的话文件直接的相对路径包含关系是怎么样的，Cmake编译的时候会进行路径搭建吗？



template <typename T, int N>
Array<T, N>::Array() //为什么这里必须加<T, N>？不加的话就是不知道是哪个T 和 N 的实例化
{
    std::memset(m_data, 0, sizeof(T) * N); // STL中的构造函数都是不进行初始化的，这里图个方便，就先全部初始化为0
}

// 这种没有定义任何行为的析构函数，在编译阶段会执行什么行为？编译器默认的是什么行为？
template <typename T, int N>
Array<T, N>::~Array()
{
}

template <typename T, int N>
int Array<T, N>::size() const
{
    return N; // 这个N是从哪里得到的啊？实参和形参都是什么？返回的是int N，是模版参数的值，既不是形参也不是实参，而是一个编译时常量。
}

template <typename T, int N>
bool Array<T, N>::empty() const
{
    return N == 0;
}

template <typename T, int N>
T *Array<T, N>::data()
{
    return m_data; // 可以对这个数据进行一些修改
}

template <typename T, int N>
const T *Array<T, N>::data() const // 数组中的内容不能被修改
{
    return m_data;
}

// 当前数组和传进来的一个数组进行交换
template <typename T, int N>
void Array<T, N>::swap(Array<T, N> &other)
{
    if (this == &other)
    {
        return;
    }
    for (int i = 0; i < N; i++)
    {
        auto temp = other.m_data[i]; // auto其实就是配合模版泛型编程来用的！
        other.m_data[i] = m_data[i]; // 这里可不可以用this.m_data[i]
        m_data[i] = temp;
    }
}

template <typename T, int N>
void Array<T, N>::fill(const T &value) // 为什么传的还是地址？既然传了地址为什么又要const？
{
    for (int i = 0; i < N; i++)
    {
        m_data[i] = value;
    }
}

template <typename T, int N>
T &Array<T, N>::front()
{
    return m_data[0]; // 不检查这个数组是不是空数组，使用的时候尽量避免空数组的操作
}

template <typename T, int N>
const T &Array<T, N>::front() const
{
    return m_data[0];
}

template <typename T, int N>
T &Array<T, N>::back()
{
    return m_data[N - 1]; //
}

template <typename T, int N>
const T &Array<T, N>::back() const
{
    return m_data[N - 1];
}

template <typename T, int N>
T &Array<T, N>::at(int index)
{
    if (index < 0 || index >= N)
        throw std::out_of_range("out of range");
    return m_data[index];
}

template <typename T, int N>
const T &Array<T, N>::at(int index) const
{
    if (index < 0 || index >= N)
        throw std::out_of_range("out of range");
    return m_data[index];
}

template <typename T, int N>
T &Array<T, N>::operator[](int index)
{
    return m_data[index]; // 返回的是引用，而不是其值的拷贝
}

template <typename T, int N>
const T &Array<T, N>::operator[](int index) const
{
    return m_data[index]; // 
}

template <typename T, int N>
void Array<T, N>::show() const
{
    std::cout << "size : " << size() << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << m_data[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T, int N>
typename Array<T, N>::iterator Array<T, N>::begin() // 还是不知道为什么要这样写 自然而然记住？ iterator也是一个依赖于模版参数的类型,也是Array<T, N>的一部分，typename 的使用是为了告诉编译器后面跟的是一个类型名称,这些都是必须的，写多了就知道了
{
    return iterator(m_data); //直接在这里调用构造函数，通过数组名传入一个指向 m_data 的指针
}

template <typename T, int N>
typename Array<T, N>::iterator Array<T, N>::end()
{
    return iterator(m_data + N);
}

template <typename T, int N>
typename Array<T, N>::const_iterator Array<T, N>::cbegin() const
{
    return const_iterator((T *)m_data); // 为什么要强转类型  应该是从非常量到常量的转换？
}

template <typename T, int N>
typename Array<T, N>::const_iterator Array<T, N>::cend() const 
{
    return const_iterator((T *)m_data + N);
}

template <typename T, int N>
typename Array<T, N>::reverse_iterator Array<T, N>::rbegin()
{
    return reverse_iterator(m_data + N - 1);
}

template <typename T, int N>
typename Array<T, N>::reverse_iterator Array<T, N>::rend()
{
    return reverse_iterator(m_data - 1);
}