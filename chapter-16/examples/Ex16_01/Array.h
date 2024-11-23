#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
private:
    T *elements;
    size_t size;

public:
    explicit Array(size_t arraysize)
    try : size{arraysize}, elements{new T[arraysize]}
    {
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "memory allocation failed for Array object.\n";
    }

    Array(const Array<T> &array)
    try : size{array.size}, elements{new T[array.size]}
    {
        for (size_t i{}; i < size; ++i)
            elements[i] = array.elements[i];
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "memory allocation failed for Array object copy.\n";
    }

    ~Array()
    {
        delete[] elements;
    }

    inline T &operator[](size_t index)
    {
        if (index < 0)
            throw std::out_of_range("Index too small: " + std::to_string(index));
        if (index >= size)
            throw std::out_of_range{"Index too large: " + std::to_string(index)};
        return elements[index];
    }

    inline const T &operator[](size_t index) const
    {
        if (index < 0)
            throw std::out_of_range("Index too small: " + std::to_string(index));
        if (index >= size)
            throw std::out_of_range{"Index too large: " + std::to_string(index)};
        return elements[index];
    }

    Array &operator=(const Array<T> &rhs)
    try
    {
        if (&rhs != this)
        {
            if (elements)
                delete[] elements;

            size = rhs.size;
            elements = new T[size];
            for (size_t i{}; i < size; ++i)
                elements[i] = rhs.elements[i];
        }
        return *this;
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "memory allocation failed for Array assignment.\n";
    }

    size_t getSize() const { return size; }
};

#endif
