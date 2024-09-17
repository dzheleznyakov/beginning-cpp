// Using an inderect base class destructor
#include <iostream>
#include <vector>
#include "Box.h"
#include "ToughPack.h"
#include "Carton.h"
#include "Can.h"

int main()
{
    std::vector<Vessel *> pVessels{
        new Box{40, 30, 20}, new Can{10, 3},
        new ToughPack{40, 30, 20}, new Carton{40, 30, 20, "plastic"}};

    for (auto p : pVessels)
        std::cout << "Volume is " << p->volume() << std::endl;

    for (auto p : pVessels)
        delete p;
}
