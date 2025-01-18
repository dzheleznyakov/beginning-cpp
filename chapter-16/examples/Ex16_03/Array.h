#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <string>
#include <type_traits>

template <typename T>
class Array
{
    static_assert(std::is_default_constructible<T>::value, "A default constructor is required");

private:
    T *elements;
    size_t size;

public:
    explicit Array(size_t arraySize);
    Array(const Array &array);
    ~Array();
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    Array &operator=(const Array &rhs);
    size_t getSize() { return size; }
};

template <typename T>
inline Array<T>::Array(size_t arraySize)
try : size{arraySize}, elements{new T[arraySize]}
{
}
catch (std::bad_alloc &)
{
    std::cerr << "memory allocation failed for Array object creation.\n";
}

template <typename T>
inline Array<T>::Array(const Array &array)
try : size{array.size}, elements{new T[array.size]}
{
    for (size_t i{}; i < size; ++i)
        elements[i] = array.elements[i];
}
catch (std::bad_alloc &)
{
    std::cerr << "memory allocation failed for Array object creaton.\n";
}

template <typename T>
inline Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
inline T &Array<T>::operator[](size_t index)
{
    if (index >= size)
        throw std::out_of_range{"Index too large: " + std::to_string(index)};
    return elements[index];
}

template <typename T>
inline const T &Array<T>::operator[](size_t index) const
{
    if (index >= size)
        throw std::out_of_range{"Index too large: " + std::to_string(index)};
    return elements[index];
}

template <typename T>
inline Array<T> &Array<T>::operator=(const Array &rhs)
try
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
catch (std::bad_alloc &)
{
    std::cerr << "memory allocation failed for Array assignment.\n";
}

#endif
