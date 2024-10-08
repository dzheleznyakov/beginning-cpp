// Using a static data member
#include <iostream>
#include "Box.h"

int main()
{
    const Box box1{2.0, 3.0, 4.0};
    Box box2{5.0};
    std::cout << "box1 volume = " << box1.volume() << std::endl;
    std::cout << "box2 volume = " << box2.volume() << std::endl;

    Box box3{box2};
    std::cout << "box3 volume = " << box3.volume() << std::endl;

    Box boxes[6]{box1, box2, box3, Box{2.0}};

    std::cout << "There are now " << box1.getObjectCount() << " objects." << std::endl;
}
