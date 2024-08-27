#include <iostream>

#include "Box.h"

int main()
{
    Box box1{};
    Box box2{1.0, 2.0, 3.0};
    Box box3(box2);

    std::cout << "box1 volume is " << box1.volume() << std::endl;
    std::cout << "box2 volume is " << box2.volume() << std::endl;
    std::cout << "box3 volume is " << box3.volume() << std::endl;
}
