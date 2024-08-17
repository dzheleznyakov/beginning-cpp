// Using a delegating constructor
#include <iostream>
#include "Box.h"

int main()
{
    Box box1{2.0, 3.0, 4.0};
    Box box2{5.0};
    std::cout << "box1 volume = " << box1.volume() << std::endl;
    std::cout << "box2 volume = " << box2.volume() << std::endl;
}
