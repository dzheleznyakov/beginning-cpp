#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack
{
private:
    class Node
    {
    public:
        T *pItem{};
        Node *pNext{};

        Node(T &item) : pItem{&item} {}
    };

    Node *pHead{};
    void copy(const Stack &stack);
    void freeMemory();

public:
    Stack() = default;
    Stack(const Stack &stack);
    ~Stack();
    Stack &operator=(const Stack &stack);

    void push(T &item);
    T &pop();
    bool isEmpty() { return !pHead; }
};

#endif

template <typename T>
inline void Stack<T>::copy(const Stack &stack)
{
    if (stack.pHead)
    {
        pHead = new Node{*stack.pHead};
        Node *pOldNode{stack.pHead};
        Node *pNewNode(pHead);

        while ((pOldNode = pOldNode->pNext))
        {
            pNewNode->pNext = new Node{*pOldNode};
            pNewNode = pNewNode->pNext;
        }
    }
}

template <typename T>
inline void Stack<T>::freeMemory()
{
    Node *pTemp{};
    while (pHead)
    {
        pTemp = pHead->pNext;
        delete pHead;
        pHead = pTemp;
    }
}

template <typename T>
Stack<T>::Stack(const Stack &stack)
{
    copy(stack);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &stack)
{
    if (this != &stack)
    {
        freeMemory();
        copy(stack);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    freeMemory();
}

template <typename T>
void Stack<T>::push(T &item)
{
    Node *pNode{new Node{item}};
    pNode->pNext = pHead;
    pHead = pNode;
}

template <typename T>
T &Stack<T>::pop()
{
    T *pItem{pHead->pItem};
    if (!pItem)
        throw std::logic_error("Stack is empty");

    Node *pTemp{pHead};
    pHead = pHead->pNext;
    delete pTemp;
    return *pItem;
}
