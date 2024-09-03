// Destructors in a class hierarchy
#include <iostream>
#include "Box.h"
#include "Carton.h"

int main()
{
    Carton carton{};
    Carton candyCarton{20.0, 30.0, 40.0, "Thin cardboard"};
    std::cout << "Volume of carton is " << carton.volume() << std::endl
              << "Volume of candyCarton is " << candyCarton.volume() << std::endl;
}
