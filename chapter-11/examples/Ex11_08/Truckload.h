#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <memory>
#include <vector>
#include "Package.h"

class Truckload
{
private:
    ptr<Package> pHead;
    ptr<Package> pTail;
    ptr<Package> pCurrent;

public:
    Truckload() {}

    Truckload(ptr<Box> pBox)
    {
        pHead = pTail = std::make_shared<Package>(pBox);
    }

    Truckload(const std::vector<ptr<Box>> &boxes);

    ptr<Box> getFirstBox();
    ptr<Box> getNextBox();
    void addBox(ptr<Box> pBox);
    bool deleteBox(ptr<Box> pBox);
    void listBoxes();
};

#endif
