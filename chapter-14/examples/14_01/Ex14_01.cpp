// Behaviour of inherited functions in a derived class
#include "Box.h"
#include "ToughPack.h"

int main()
{
    Box box{20.0, 30.0, 40.0};
    ToughPack hardcase{20.0, 30.0, 40.0};

    box.showVolume();
    hardcase.showVolume();

    std::cout << "hardcase volume is " << hardcase.volume() << std::endl;
    Box *pBox{&hardcase};
    std::cout << "hardcase volume through pBox is " << pBox->volume() << std::endl;
}
