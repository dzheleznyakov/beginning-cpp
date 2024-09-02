// Defining and useing a derived class
#include <iostream>
#include "Box.h"
#include "Carton.h"

int main()
{
    Box box{40.0, 30.0, 20.0};
    Carton carton;
    Carton candyCarton{"Thin cardboard"};

    std::cout << "box occupies " << sizeof box << " bytes" << std::endl;
    std::cout << "carton occupies " << sizeof carton << " bytes" << std::endl;
    std::cout << "candyCarto occupies " << sizeof candyCarton << " bytes" << std::endl;

    std::cout << "box volume is " << box.volume() << std::endl;
    std::cout << "carton volume is " << carton.volume() << std::endl;
    std::cout << "candyCarton volume is " << candyCarton.volume() << std::endl;

    std::cout << "candyCarton length is " << candyCarton.getLength() << std::endl;
}
