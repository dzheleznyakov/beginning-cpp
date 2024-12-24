#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <string>

template <typename T, int startIndex>
class Array
{
private:
    T *elements;
    size_t size;

public:
    explicit Array(size_t arraySize);
    explicit Array(const Array &array);
    ~Array();

    T &operator[](int index);
    const T &operator[](int index) const;
    Array &operator=(const Array &rhs);

    size_t getSize() { return size; };
};

template <typename T, int startIndex>
inline Array<T, startIndex>::Array(size_t arraySize)
    : size{arraySize}, elements{new T[arraySize]} {}

template <typename T, int startIndex>
inline Array<T, startIndex>::Array(const Array &array)
    : size{array.size}, elements{new T[array.size]}
{
    for (size_t i{}; i < size; ++i)
    {
        elements[i] = array.elements[i];
    }
}

template <typename T, int startIndex>
inline Array<T, startIndex>::~Array()
{
    delete[] elements;
}

template <typename T, int startIndex>
T &Array<T, startIndex>::operator[](int index)
{
    if (index > startIndex + static_cast<int>(size) - 1)
        throw std::out_of_range{"Index too large: " + std::to_string(index)};

    if (index < startIndex)
        throw std::out_of_range{"Index too small: " + std::to_string(index)};

    return elements[index - startIndex];
}

template <typename T, int startIndex>
const T &Array<T, startIndex>::operator[](int index) const
{
    if (index > startIndex + static_cast<int>(size) - 1)
        throw std::out_of_range{"Index too large: " + std::to_string(index)};

    if (index < startIndex)
        throw std::out_of_range{"Index too small: " + std::to_string(index)};

    return elements[index - startIndex];
}

template <typename T, int startIndex>
Array<T, startIndex> &Array<T, startIndex>::operator=(const Array &rhs)
{
    if (&rhs != this)
    {
        if (elements)
            delete[] elements;

        size = rhs.size;
        elements = new T[rhs.size];
        for (size_t i{}; i < size; ++i)
            elements[i] = rhs.elements[i];
    }
    return *this;
}

#endif
