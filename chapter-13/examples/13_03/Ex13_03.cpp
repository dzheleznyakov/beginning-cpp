// Using a derived class copy constructor
#include <iostream>
#include "Box.h"
#include "Carton.h"

int main()
{
    Carton carton{20.0, 30.0, 40.0, "Glassine board"};
    Carton cartonCopy{carton};
    std::cout << "Volume of carton is " << carton.volume() << std::endl
              << "Volume of cartonCopy is " << cartonCopy.volume() << std::endl;
}
