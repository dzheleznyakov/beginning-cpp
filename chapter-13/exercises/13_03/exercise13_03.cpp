#include <iostream>
#include "Lion.h"
#include "Aardvark.h"

int main()
{
    Lion lion{"Leo", 400};
    Aardvark aardvark{"Algernon", 50};

    std::cout << lion.Animal::who() << std::endl;
    std::cout << lion.who() << std::endl;
    std::cout << aardvark.Animal::who() << std::endl;
    std::cout << aardvark.who() << std::endl;
}
