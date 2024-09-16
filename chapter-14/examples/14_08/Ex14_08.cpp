// Using an inderect base class
#include <iostream>
#include <vector>
#include "Box.h"
#include "ToughPack.h"
#include "Carton.h"
#include "Can.h"

int main()
{
    Box box{40.0, 30.0, 20.0};
    Can can{10, 3};
    ToughPack hardcase{40.0, 30.0, 20.0};
    Carton carton{40.0, 30.0, 20.0, "plastic"};

    std::vector<Vessel *> pVessels{&box, &can, &carton, &hardcase};

    for (auto p : pVessels)
        std::cout << "Volume is " << p->volume() << std::endl;
}
