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

ptr<Box> Truckload::getLastBox()
{
    pCurrent = pTail->getPrev();
    return pTail->getBox();
}

ptr<Box> Truckload::getPrevBox()
{
    if (!pCurrent)
        return getLastBox();

    auto pPackage = pCurrent->getPrev();
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
    {
        pTail->setNext(pPackage);
        pPackage->setPrev(pTail);
    }
    else
        pHead = pPackage;
    pTail = pPackage;
}

bool Truckload::deleteBox(ptr<Box> pBox)
{
    pCurrent = pHead;
    while (pCurrent)
    {
        if (pCurrent->getBox() == pBox)
        {
            if (pCurrent->getPrev())
                pCurrent->getPrev()->setNext(pCurrent->getNext());
            else
                pHead = pHead->getNext();
            if (pCurrent->getNext())
                pCurrent->getNext()->setPrev(pCurrent->getPrev());
            else
                pTail = pTail->getPrev();
            pCurrent = nullptr;
            return true;
        }
        pCurrent = pCurrent->getNext();
    }
    return false;
}

void Truckload::listBoxesInOrder(
    const ptr<Package> &pFirst,
    std::function<ptr<Package> &(const ptr<Package> &)> getNextInOrder)
{
    pCurrent = pFirst;
    size_t count{};
    while (pCurrent)
    {
        pCurrent->getBox()->listBox();
        pCurrent = getNextInOrder(pCurrent);
        if (!(++count % 5))
            std::cout << std::endl;
    }
    if (count % 5)
        std::cout << std::endl;
}

void Truckload::listBoxes()
{
    listBoxesInOrder(pHead, [](const ptr<Package> &pPackage) -> ptr<Package> &
                     { return pPackage->getNext(); });
}

void Truckload::listBoxesReversed()
{
    listBoxesInOrder(pTail, [](const ptr<Package> pPackage) -> ptr<Package> &
                     { return pPackage->getPrev(); });
}
