#ifndef TRUCKLOAD_H_11_05
#define TRUCKLOAD_H_11_05

#include <functional>
#include <memory>
#include <vector>

#include "Package.h"

class Truckload
{
private:
    ptr<Package> pHead;
    ptr<Package> pTail;
    ptr<Package> pCurrent;

    void listBoxesInOrder(
        const ptr<Package> &pFirst,
        std::function<ptr<Package> &(const ptr<Package> &)> getNextInOrder);

public:
    Truckload() {}

    Truckload(ptr<Box> pBox)
    {
        pHead = pTail = std::make_shared<Package>(pBox);
    }

    Truckload(const std::vector<ptr<Box>> &boxes);

    ptr<Box> getFirstBox();
    ptr<Box> getNextBox();
    ptr<Box> getLastBox();
    ptr<Box> getPrevBox();
    void addBox(ptr<Box> pBox);
    bool deleteBox(ptr<Box> pBox);
    void listBoxes();
    void listBoxesReversed();
};

#endif
