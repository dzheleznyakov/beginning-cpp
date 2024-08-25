#ifndef PACKAGE_H_11_05
#define PACKAGE_H_11_05

#include <memory>
#include "Box.h"

template <typename T>
using ptr = std::shared_ptr<T>;

class Package
{
private:
    ptr<Box> pBox;
    ptr<Package> pNext;
    ptr<Package> pPrev;

public:
    Package(ptr<Box> pb) : pBox{pb}, pNext{}, pPrev{} {}

    ptr<Box> &getBox()
    {
        return pBox;
    }

    ptr<Package> &getNext()
    {
        return pNext;
    }

    ptr<Package> &getPrev()
    {
        return pPrev;
    }

    void setNext(ptr<Package> &pPackage)
    {
        pNext = pPackage;
    }

    void setPrev(ptr<Package> &pPackage)
    {
        pPrev = pPackage;
    }
};

#endif
