/*
    Define an operator function that will allow a Box object
    to be premultiplied by an integer n to produce the same result as
    the operator in Exercise 12-01.
*/
#include <iostream>

#include "Box.h"

int main()
{
    Box box1{1.0, 2.0, 3.0};
    Box box2{4 * box1};

    std::cout << "box1" << box1 << " has volume " << box1.volume() << std::endl;
    std::cout << "box2" << box2 << " has volume " << box2.volume() << std::endl;
}
