#include <iostream>
#include "Box.h"

size_t Box::objectCount{};

Box::Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
{
    ++objectCount;
    std::cout << "Box constructor 1 called." << std::endl;
}

double Box::volume() const
{
    return length * width * height;
}
