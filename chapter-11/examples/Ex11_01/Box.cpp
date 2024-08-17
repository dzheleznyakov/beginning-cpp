#include <iostream>
#include "Box.h"

Box::Box(double lengthValue, double widthValue, double heightValue)
{
    std::cout << "Box constructor called" << std::endl;
    length = lengthValue;
    width = widthValue;
    height = heightValue;
}

Box::Box() {}

double Box::volume()
{
    return length * width * height;
}
