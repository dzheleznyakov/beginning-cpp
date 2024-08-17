#include <iostream>
#include "Box.h"

Box::Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
{
    std::cout << "Box constructor 1 called." << std::endl;
}

Box::Box(double side) : Box{side, side, side}
{
    std::cout << "Box constructor 2 called." << std::endl;
}

double Box::volume()
{
    return length * width * height;
}
