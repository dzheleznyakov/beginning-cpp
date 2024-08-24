#include <memory>
#include <vector>
#include "Box.h"
#include "Package.h"
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
    pCurrent = pHead->getNext();
    return pHead->getBox();
}

ptr<Box> Truckload::getNextBox()
{
    if (!pCurrent)
        return getFirstBox();

    auto pPackage = pCurrent->getNext();
    if (pPackage)
    {
        pCurrent = pPackage;
        return pPackage->getBox();
    }
    pCurrent = nullptr;
    return nullptr;
}

void Truckload::addBox(ptr<Box> pBox)
{
    auto pPackage = std::make_shared<Package>(pBox);
    if (pHead)
        pTail->setNext(pPackage);
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
        if (pCurrent->getBox() == pBox)
        {
            if (pPrevious)
                pPrevious->setNext(pCurrent->getNext());
            else
                pHead = pHead->getNext();
            pCurrent = nullptr;
            return true;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->getNext();
    }
    return false;
}

void Truckload::listBoxes()
{
    pCurrent = pHead;
    size_t count{};
    while (pCurrent)
    {
        pCurrent->getBox()->listBox();
        pCurrent = pCurrent->getNext();
        if (!(++count % 5))
            std::cout << std::endl;
    }
    if (count % 5)
        std::cout << std::endl;
}
