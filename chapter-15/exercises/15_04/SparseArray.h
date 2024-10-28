#ifndef SPARSE_ARRAY_H
#define SPARSE_ARRAY_H

#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
using ptr = std::shared_ptr<T>;

class NotEnoughCapacityException : public std::exception
{
};

class OutOfBoundException : public std::exception
{
};

class SparseArray
{
private:
    size_t capacity;
    size_t currentSize{};

public:
    SparseArray(size_t capV) : capacity{capV}
    {
        pHead = nullptr;
        pTail = nullptr;
    }

    size_t size() const;
    double operator[](size_t index) const;

    void fill();
    void add(double value);
    void add(size_t index, double value);
    void set(size_t index, double value);
    void remove(size_t index);

    friend std::ostream &operator<<(std::ostream &stream, const SparseArray &array);

private:
    class Node
    {
    public:
        ptr<Node> prev;
        ptr<Node> next;

        size_t index;
        double value;

        Node(size_t i, double v) : index{i}, value{v} {}
    };

private:
    ptr<Node> pHead;
    ptr<Node> pTail;
};

#endif
