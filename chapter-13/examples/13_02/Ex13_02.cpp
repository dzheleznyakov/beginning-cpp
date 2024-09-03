// Calling base class constructors in a derived class constructors
#include "Carton.h"

int main()
{
    Carton carton1;
    Carton carton2{"Thin cardboard"};
    Carton carton3{4.0, 5.0, 6.0, "Plastic"};
    Carton carton4{2.0, "Paper"};

    std::cout << "carton1 volume is " << carton1.volume() << std::endl;
    std::cout << "carton2 volume is " << carton2.volume() << std::endl;
    std::cout << "carton3 volume is " << carton3.volume() << std::endl;
    std::cout << "carton4 volume is " << carton4.volume() << std::endl;
}
