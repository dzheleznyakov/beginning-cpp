/*
    Define an operator function in the Box class from Example 12-08
    that allows a Box object to be multiplied by an integer, n,
    to produce a new object that has a height that is n times to original object.
*/
#include <iostream>

#include "Box.h"

int main()
{
    Box box1{1.0, 2.0, 3.0};
    Box box2{box1 * 4};

    std::cout << "box1 " << box1 << " has volume " << box1.volume() << std::endl;
    std::cout << "box2 " << box2 << " has volume " << box2.volume() << std::endl;
}
