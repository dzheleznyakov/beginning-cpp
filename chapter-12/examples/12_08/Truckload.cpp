#include <memory>
#include <vector>
#include "Box.h"
#include "Truckload.h"

ptr<Box> Truckload::nullBox{};

Truckload::Truckload(const std::vector<ptr<Box>> &boxes)
{
    for (auto pBox : boxes)
    {
        addBox(pBox);
    }
}

ptr<Box> Truckload::getFirstBox()
{
    pCurrent = pHead->pNext;
    return pHead->pBox;
}

ptr<Box> Truckload::getNextBox()
{
    if (!pCurrent)
        return getFirstBox();

    auto pPackage = pCurrent->pNext;
    if (pPackage)
    {
        pCurrent = pPackage;
        return pPackage->pBox;
    }
    pCurrent = nullptr;
    return nullptr;
}

void Truckload::addBox(ptr<Box> pBox)
{
    auto pPackage = std::make_shared<Package>(pBox);
    if (pHead)
        pTail->pNext = pPackage;
    else
        pHead = pPackage;
    pTail = pPackage;
}

bool Truckload::deleteBox(ptr<Box> pBox)
{
    pCurrent = pHead;
    ptr<Package> pPrevious;
    while (pCurrent)
    {
        if (pCurrent->pBox == pBox)
        {
            if (pPrevious)
                pPrevious->pNext = pCurrent->pNext;
            else
                pHead = pHead->pNext;
            pCurrent = nullptr;
            return true;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    return false;
}

std::ostream &operator<<(std::ostream &stream, Truckload &load)
{
    load.pCurrent = load.pHead;
    size_t count{};
    while (load.pCurrent)
    {
        std::cout << *(load.pCurrent->pBox);
        load.pCurrent = load.pCurrent->pNext;
        if (!(++count % 5))
            std::cout << std::endl;
    }
    if (count % 5)
        std::cout << std::endl;
    return stream;
}

ptr<Box> &Truckload::operator[](size_t index) const
{
    ptr<Package> pCurrentPackage{pHead};
    size_t count{};
    do
    {
        if (index == count++)
            return pCurrentPackage->pBox;
        pCurrentPackage = pCurrentPackage->pNext;
    } while (pCurrentPackage);
    return nullBox;
}
