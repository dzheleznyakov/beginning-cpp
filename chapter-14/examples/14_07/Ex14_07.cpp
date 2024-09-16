// Using a abstract class
#include <iostream>
#include "Box.h"
#include "ToughPack.h"
#include "Carton.h"

int main()
{
    ToughPack hardcase{20.0, 30.0, 40.0};
    Carton carton{20.0, 30.0, 40.0, "plastic"};

    Box *pBox{&hardcase};
    std::cout << "hardcase volume is " << pBox->volume() << std::endl;

    pBox = &carton;
    std::cout << "carton volume is " << pBox->volume() << std::endl;
}
