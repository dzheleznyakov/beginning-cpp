// Using multiple inheritance
#include <iostream>
#include "Cerealpack.h"

int main()
{
    CerealPack cornflakes{8.0, 3.0, 10.0, "Cornflakes"};
    std::cout << "cornflakes volume is " << cornflakes.Carton::volume() << std::endl
              << "cornflakes weight is " << cornflakes.Contents::getWeight() << std::endl;
}
