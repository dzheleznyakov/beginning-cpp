// Default parameters in virtual functions
#include <iostream>
#include "Box.h"
#include "ToughPack.h"
#include "Carton.h"

int main()
{
    Box box{20.0, 30.0, 40.0};
    ToughPack hardcase{20.0, 30.0, 40.0};
    Carton carton{20.0, 30.0, 40.0, "plastic"};

    box.showVolume();
    hardcase.showVolume();
    carton.showVolume();

    Box *pBox{&box};
    std::cout << "\nbox volume through pBox is " << pBox->volume() << std::endl;
    pBox->showVolume();

    pBox = &hardcase;
    std::cout << "\nhardcase volume through pBox is " << pBox->volume() << std::endl;
    pBox->showVolume();

    pBox = &carton;
    std::cout << "\ncarton volume through pBox is " << pBox->volume() << std::endl;
    pBox->showVolume();
}
