#ifndef PACKAGE_H
#define PACKAGE_H

#include <memory>
#include "Box.h"

template <typename T>
using ptr = std::shared_ptr<T>;

class Package
{
private:
    ptr<Box> pBox;
    ptr<Package> pNext;

public:
    Package(ptr<Box> pb) : pBox{pb}, pNext{} {}

    ptr<Box> &getBox()
    {
        return pBox;
    }

    ptr<Package> &getNext()
    {
        return pNext;
    }

    void setNext(ptr<Package> &pPackage)
    {
        pNext = pPackage;
    }
};

#endif
