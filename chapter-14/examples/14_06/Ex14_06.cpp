// Using a reference parameter to call virtual function
#include <iostream>
#include "Box.h"
#include "ToughPack.h"
#include "Carton.h"

void showVolume(Box &rBox)
{
    std::cout << "Box usable volume is " << rBox.volume() << std::endl;
}

int main()
{
    Box box{20.0, 30.0, 40.0};
    ToughPack hardcase{20.0, 30.0, 40.0};
    Carton carton{20.0, 30.0, 40.0, "plastic"};

    showVolume(box);
    showVolume(hardcase);
    showVolume(carton);
}
