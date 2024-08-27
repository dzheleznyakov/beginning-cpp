#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <memory>
#include <vector>
#include "Box.h"

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

    static ptr<Box> nullBox;

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
    ptr<Box> &operator[](size_t index) const;

    friend std::ostream &operator<<(std::ostream &stream, Truckload &load);
};

#endif
