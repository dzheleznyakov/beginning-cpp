#include <iostream>
#include "Box.h"

Box::Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
{
    std::cout << "Box constructor 1 called." << std::endl;
}

double Box::volume() const
{
    return width * length * height;
}
