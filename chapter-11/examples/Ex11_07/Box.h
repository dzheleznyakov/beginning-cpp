#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};
    static size_t objectCount;

public:
    Box(double lv, double wv, double hv);

    Box(double side) : Box{side, side, side}
    {
        std::cout << "Box constructor 2 called." << std::endl;
    }

    Box()
    {
        ++objectCount;
        std::cout << "No-arg Box constructor called." << std::endl;
    }

    Box(const Box &box) : length{box.length}, width{box.width}, height{box.height}
    {
        ++objectCount;
        std::cout << "Box copy constructor called." << std::endl;
    }

    double volume() const;

    static size_t getObjectCount()
    {
        return objectCount;
    }

    ~Box()
    {
        std::cout << "Box destructor called." << std::endl;
        --objectCount;
    }
};

#endif