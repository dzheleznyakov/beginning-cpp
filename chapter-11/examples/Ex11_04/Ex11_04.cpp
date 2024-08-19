// Using a friend function of a class
#include <iostream>
#include <memory>
#include "Box.h"

int main()
{
    Box box1{2.2, 1.1, 0.5};
    Box box2;
    auto pBox3 = std::make_shared<Box>(15.0, 20.0, 8.0);

    std::cout << "Volume of box1 = " << box1.volume() << std::endl;
    std::cout << "Surface area of box1 = " << surfaceArea(box1) << std::endl;

    std::cout << "Volume of box2 = " << box2.volume() << std::endl;
    std::cout << "Surface area of box2 = " << surfaceArea(box2) << std::endl;

    std::cout << "Volume of box3 = " << pBox3->volume() << std::endl;
    std::cout << "Surface area of box3 = " << surfaceArea(*pBox3) << std::endl;
}

double surfaceArea(const Box &aBox)
{
    return 2.0 * (aBox.length * aBox.width + aBox.length * aBox.height + aBox.width * aBox.height);
}
