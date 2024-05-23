// Vector<T>会报错。尝试写cmake,可以编译成功但是还是报红。应该是与Cmake无关的？
// 命名ctrl键都可以关联到，为什么会说它不是一个模版。不是拼写错误，array也不会报错;重启也不行。我他妈直接一个disable，直接就没问题

template <typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

template <typename T>
Vector<T>::~Vector()
{
    if (m_data != nullptr)
    {
        delete[] m_data; // 释放连续的内存空间用这个？
    }
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
T &Vector<T>::at(int index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("at  out_of_range");
    }
    return m_data[index]; // 这里返回的是元素，为什么又是引用？
}

template <typename T>
const T &Vector<T>::at(int index) const
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("at  out_of_range");
    }
    return m_data[index];
}
template <typename T>
T &Vector<T>::front()
{
    return m_data[0];
}

template <typename T>
const T &Vector<T>::front() const
{
    return m_data[0];
}

template <typename T>
T &Vector<T>::back()
{
    return m_data[m_size - 1];
}

template <typename T>
const T &Vector<T>::back() const
{
    return m_data[m_size - 1];
}
template <typename T>
T *Vector<T>::data()
{
    return m_data; // 这个就是指针类型的
}

template <typename T>
const T *Vector<T>::data() const
{
    return m_data;
}

template <typename T>
T &Vector<T>::operator[](int index)
{
    return m_data[index]; //指针有默认的这种写法吗？
}

template <typename T>
const T &Vector<T>::operator[](int index) const
{
    return m_data[index];
}