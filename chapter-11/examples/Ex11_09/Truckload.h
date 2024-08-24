#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <memory>
#include <vector>

template <typename T>
using ptr = std::shared_ptr<T>;

class Truckload
{
private:
    class Package
    {
    public:
        ptr<Box> pBox;
        ptr<Package> pNext;

        Package(ptr<Box> pb) : pBox{pb}, pNext{} {}
    };

    ptr<Package>
        pHead;
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
