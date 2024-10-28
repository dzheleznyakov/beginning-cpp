#include "SparseArray.h"

size_t SparseArray::size() const
{
    return currentSize;
}

double SparseArray::operator[](size_t index) const
{
    if (index < 0 || index >= currentSize)
        throw OutOfBoundException{};

    ptr<Node> pCurr{pHead};
    while (pCurr != nullptr)
    {
        if (index == pCurr->index)
            return pCurr->value;
        if (index < pCurr->index)
            return 0.0;
        pCurr = pCurr->next;
    }
    return 0.0;
}

void SparseArray::fill()
{
    currentSize = capacity;
}

void SparseArray::add(double value)
{
    if (currentSize == capacity)
        throw NotEnoughCapacityException{};

    if (value == 0.0)
    {
        ++currentSize;
        return;
    }

    ptr<Node> pNode = std::make_shared<Node>(currentSize, value);
    if (pTail == nullptr)
    {
        pHead = pNode;
        pTail = pNode;
    }
    else
    {
        pTail->next = pNode;
        pNode->prev = pTail;
        pTail = pNode;
    }

    ++currentSize;
}

void SparseArray::add(size_t index, double value)
{
    if (index < 0)
        throw OutOfBoundException{};
    if (currentSize == capacity || index + 1 > capacity)
        throw NotEnoughCapacityException{};

    ptr<Node> pNew = std::make_shared<Node>(index, value);

    ptr<Node> pCurr{pHead};
    while (true)
    {
        if (pCurr == nullptr)
        {
            if (pHead == nullptr)
            {
                pHead = pNew;
                pTail = pNew;
            }
            else
            {
                pTail->next = pNew;
                pNew->prev = pTail;
                pTail = pNew;
            }
            break;
        }

        if (index <= pCurr->index)
        {
            if (value == 0.0)
                break;
            ptr<Node> pPrev{pCurr->prev};

            pNew->prev = pPrev;
            if (pPrev != nullptr)
                pPrev->next = pNew;
            if (pPrev == nullptr)
                pHead = pNew;

            pNew->next = pCurr;
            pCurr->prev = pNew;

            break;
        }
        pCurr = pCurr->next;
    }

    while (pCurr != nullptr)
    {
        ++(pCurr->index);
        pCurr = pCurr->next;
    }

    if (index <= currentSize)
    {
        ++currentSize;
    }
    else
    {
        currentSize = index + 1;
    }
}

void SparseArray::set(size_t index, double value)
{
    if (index < 0 || index >= currentSize)
        throw OutOfBoundException{};

    ptr<Node> pCurr{pHead};
    while (true)
    {
        if (pCurr == nullptr)
        {
            if (value == 0.0)
                break;
            ptr<Node> pNew = std::make_shared<Node>(index, value);
            if (pHead == nullptr)
            {
                pHead = pNew;
                pTail = pNew;
            }
            else
            {
                pTail->next = pNew;
                pNew->prev = pTail;
                pTail = pNew;
            }
            break;
        }
        if (index == pCurr->index)
        {
            if (value != 0.0)
            {
                pCurr->value = value;
                break;
            }
            ptr<Node> pPrev{pCurr->prev};
            ptr<Node> pNext{pCurr->next};
            if (pPrev != nullptr)
                pPrev->next = pNext;
            if (pNext != nullptr)
                pNext->prev = pPrev;
            if (pPrev == nullptr)
                pHead = pNext;
            if (pNext == nullptr)
                pTail = pPrev;
            break;
        }
        if (index < pCurr->index)
        {
            if (value == 0.0)
            {
                break;
            }
            ptr<Node> pNew = std::make_shared<Node>(index, value);
            ptr<Node> pPrev{pCurr->prev};

            pNew->prev = pPrev;
            if (pPrev != nullptr)
                pPrev->next = pNew;

            pNew->next = pCurr;
            pCurr->prev = pNew;

            if (pPrev == nullptr)
                pHead = pNew;

            break;
        }

        pCurr = pCurr->next;
    }
}

void SparseArray::remove(size_t index)
{
    if (index < 0 || index >= currentSize)
        throw OutOfBoundException{};

    ptr<Node> pCurr{pHead};
    while (true)
    {
        if (pCurr == nullptr || index < pCurr->index)
            break;
        if (index == pCurr->index)
        {
            ptr<Node> pPrev{pCurr->prev};
            ptr<Node> pNext{pCurr->next};
            if (pPrev != nullptr)
                pPrev->next = pNext;
            if (pNext != nullptr)
                pNext->prev = pPrev;
            if (pPrev == nullptr)
                pHead = pNext;
            if (pNext == nullptr)
                pTail = pPrev;
            break;
        }

        pCurr = pCurr->next;
    }

    while (pCurr != nullptr)
    {
        --(pCurr->index);
        pCurr = pCurr->next;
    }

    --currentSize;
}

std::ostream &operator<<(std::ostream &stream, const SparseArray &array)
{
    stream << "SparseArray[";

    ptr<SparseArray::Node> pNextNode{array.pHead};
    for (size_t i{}; i < array.size(); ++i)
    {
        if (pNextNode == nullptr || i < pNextNode->index)
            stream << 0.0;
        if (pNextNode != nullptr && i == pNextNode->index)
        {
            stream << pNextNode->value;
            pNextNode = pNextNode->next;
        }
        if (i < array.size() - 1)
            stream << ", ";
    }

    stream << "]";
    return stream;
}
