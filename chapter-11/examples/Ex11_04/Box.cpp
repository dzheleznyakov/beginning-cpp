#include <iostream>
#include "Box.h"

Box::Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
{
    std::cout << "Box constructor called" << std::endl;
}

double Box::volume()
{
    return length * width * height;
}
