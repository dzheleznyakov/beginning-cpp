#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>

template <typename T>
class LinkedList
{
private:
    class Node;
    using PNode = std::shared_ptr<Node>;

    class Node
    {
    public:
        PNode pNext;
        PNode pPrev;
        T *pValue;

        Node(const T &value) : pValue{new T(value)} {}
        ~Node() { delete pValue; }
    };

    PNode pHead;
    PNode pTail;

public:
    void add(const T &value);

    friend std::ostream &operator<<(std::ostream &stream, const LinkedList<T> &list)
    {
        stream << '[';
        PNode pCurr{list.pHead};
        while (pCurr)
        {
            stream << *pCurr->pValue;
            if (pCurr->pNext)
                stream << ", ";
            pCurr = pCurr->pNext;
        }
        stream << ']';
        return stream;
    }

    class ForwardIterator
    {
    private:
        PNode pNext;

    public:
        ForwardIterator(const PNode &pStart) : pNext{pStart} {}
        bool hasNext() { return pNext != nullptr; }
        T &next()
        {
            PNode pResult{pNext};
            pNext = pNext->pNext;
            return *pResult->pValue;
        }
    };

    class ReverseIterator
    {
    private:
        PNode pNext;

    public:
        ReverseIterator(const PNode &pStart) : pNext{pStart} {}
        bool hasNext() { return pNext != nullptr; }
        T &next()
        {
            PNode pResult{pNext};
            pNext = pNext->pPrev;
            return *pResult->pValue;
        }
    };

    ForwardIterator forward() const
    {
        ForwardIterator iterator{pHead};
        return iterator;
    }

    ReverseIterator reverse() const
    {
        ReverseIterator iterator{pTail};
        return iterator;
    }
};

template <typename T>
inline void LinkedList<T>::add(const T &value)
{
    PNode pNew = std::make_shared<Node>(value);
    if (!pHead)
        pTail = pHead = pNew;
    else
    {
        pTail->pNext = pNew;
        pNew->pPrev = pTail;
        pTail = pNew;
    }
}

#endif
