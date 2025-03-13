#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>
#include <functional>

template <typename T>
class Iterator
{
public:
    virtual bool hasNext() const = 0;
    virtual T &next() = 0;
};

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

private:
    class ForwardIterator : public Iterator<T>
    {
    public:
        PNode pNext;

        ForwardIterator(const PNode &pStart) : pNext{pStart} {}
        bool hasNext() const { return pNext != nullptr; }
        T &next()
        {
            PNode pResult{pNext};
            pNext = pNext->pNext;
            return *pResult->pValue;
        }
    };

    class ReverseIterator : public Iterator<T>
    {
    public:
        PNode pNext;

        ReverseIterator(const PNode &pStart) : pNext{pStart} {}
        bool hasNext() const { return pNext != nullptr; }
        T &next()
        {
            PNode pResult{pNext};
            pNext = pNext->pPrev;
            return *pResult->pValue;
        }
    };

    using Consumer = std::function<void(T &)>;
    using ConstConsumer = std::function<void(const T &)>;
    void forEach(Iterator<T> *iterator, Consumer consumer);
    void forEach(Iterator<T> *iterator, ConstConsumer consumer) const;

public:
    void forEach(Consumer consumer);
    void forEach(ConstConsumer consumer) const;
    void forEachReversed(Consumer consumer);
    void forEachReversed(ConstConsumer consumer) const;
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

template <typename T>
inline void LinkedList<T>::forEach(Iterator<T> *iterator, Consumer consumer)
{
    while (iterator->hasNext())
        consumer(iterator->next());
}

template <typename T>
inline void LinkedList<T>::forEach(Iterator<T> *iterator, ConstConsumer consumer) const
{
    while (iterator->hasNext())
        consumer(iterator->next());
}

template <typename T>
inline void LinkedList<T>::forEach(Consumer consumer)
{
    ForwardIterator iterator{pHead};
    forEach(&iterator, consumer);
}

template <typename T>
inline void LinkedList<T>::forEach(ConstConsumer consumer) const
{
    ForwardIterator iterator{pHead};
    forEach(&iterator, consumer);
}

template <typename T>
inline void LinkedList<T>::forEachReversed(Consumer consumer)
{
    ReverseIterator iterator{pTail};
    forEach(&iterator, consumer);
}

template <typename T>
inline void LinkedList<T>::forEachReversed(ConstConsumer consumer) const
{
    ReverseIterator iterator{pTail};
    forEach(&iterator, consumer);
}

#endif
