#include <memory>
#include <vector>
#include "Box.h"
#include "Truckload.h"

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

void Truckload::listBoxes()
{
    pCurrent = pHead;
    size_t count{};
    while (pCurrent)
    {
        pCurrent->pBox->listBox();
        pCurrent = pCurrent->pNext;
        if (!(++count % 5))
            std::cout << std::endl;
    }
    if (count % 5)
        std::cout << std::endl;
}
