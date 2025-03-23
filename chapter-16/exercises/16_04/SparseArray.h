#ifndef SPARCE_ARRAY_H
#define SPARCE_ARRAY_H

#include <type_traits>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>

template <typename T>
class SparseArray
{
    static_assert(std::is_default_constructible<T>::value, "A default constructor is required");

private:
    class Node;
    using PNode = std::shared_ptr<Node>;

    void removeNodes();

private:
    class Node
    {
    public:
        PNode pPrev;
        PNode pNext;
        size_t index{};
        T *pValue;

        Node(size_t i) : index{i}, pValue{new T} {};
        Node(const Node &node) : index{node.index}, pValue{new T(*node.pValue)} {};
        ~Node() { delete pValue; };
    };

    PNode pHead{};
    PNode pTail{};

public:
    SparseArray() = default;
    SparseArray(const SparseArray &array);

    using Consumer = std::function<void(size_t index, T &)>;
    using ConstConsumer = std::function<void(const size_t index, const T &)>;
    void forEach(Consumer consumer);
    void forEach(ConstConsumer consumer) const;

    SparseArray &operator=(const SparseArray &rhs);
    T &operator[](size_t index);

    void insert(T &value);
    size_t size();

    friend std::ostream &operator<<(std::ostream &stream, const SparseArray<T> &array)
    {
        stream << '[';
        PNode pCurr = array.pHead;
        while (true)
        {
            if (!pCurr)
                break;
            stream << pCurr->index << ':' << *pCurr->pValue;
            pCurr = pCurr->pNext;
            if (pCurr)
                stream << ", ";
        }
        stream << ']';
        return stream;
    }
};

template <typename T>
inline void SparseArray<T>::removeNodes()
{
    PNode pCurr{pHead};
    while (pCurr)
    {
        PNode pNext{pCurr->pNext};
        pCurr->pNext = nullptr;
        pCurr->pPrev = nullptr;
        pCurr = pNext;
    }

    pHead = nullptr;
    pTail = nullptr;
}

template <typename T>
inline SparseArray<T>::SparseArray(const SparseArray &array)
{
    *this = array;
}

template <typename T>
inline SparseArray<T> &SparseArray<T>::operator=(const SparseArray &rhs)
{
    if (this == &rhs)
        return *this;

    removeNodes();

    PNode pCurr;
    if (rhs.pHead)
    {
        pTail = pHead = std::make_shared<Node>(*rhs.pHead);
        PNode pTemp;
        pCurr = rhs.pHead;
        while ((pCurr = pCurr->pNext))
        {
            pTemp = pTail;
            pTail = std::make_shared<Node>(*pCurr);
            pTemp->pNext = pTail;
            pTail->pPrev = pTemp;
            pTemp = pTail;
        }
    }

    return *this;
}

template <typename T>
inline T &SparseArray<T>::operator[](size_t index)
{
    if (index < 0)
        throw std::out_of_range{"index cannot be less than 0."};

    PNode pCurr{pHead};
    PNode pResult{};
    while (true)
    {
        if (pCurr == nullptr)
        {
            PNode pNew = std::make_shared<Node>(index);
            if (pHead == nullptr)
            {
                pHead = pNew;
                pTail = pNew;
                pResult = pNew;
            }
            else
            {
                pTail->pNext = pNew;
                pNew->pPrev = pTail;
                pTail = pNew;
                pResult = pNew;
            }
            break;
        }

        if (index < pCurr->index)
        {
            PNode pNew = std::make_shared<Node>(index);
            PNode pPrev = pCurr->pPrev;

            pNew->pPrev = pPrev;
            if (pPrev != nullptr)
                pPrev->pNext = pNew;
            if (pPrev == nullptr)
                pHead = pNew;

            pNew->pNext = pCurr;
            pCurr->pPrev = pNew;

            pResult = pNew;
            break;
        }

        if (index == pCurr->index)
        {
            pResult = pCurr;
            break;
        }

        pCurr = pCurr->pNext;
    }

    return *pResult->pValue;
}

template <typename T>
inline size_t SparseArray<T>::size()
{
    if (pTail)
        return pTail->index + 1;
    return 0;
}

template <typename T>
inline void SparseArray<T>::forEach(Consumer consumer)
{
    PNode pCurr = pHead;
    while (pCurr)
    {
        consumer(pCurr->index, *pCurr->pValue);
        pCurr = pCurr->pNext;
    }
}

template <typename T>
inline void SparseArray<T>::forEach(ConstConsumer consumer) const
{
    PNode pCurr = pHead;
    while (pCurr)
    {
        consumer(pCurr->index, *pCurr->pValue);
        pCurr = pCurr->pNext;
    }
}

template <typename T>
inline void SparseArray<T>::insert(T &value)
{
    (*this)[size()] = value;
}

#endif
