// Virtual funcions using smart pointers
#include <iostream>
#include <memory>
#include <vector>
#include "Box.h"
#include "Carton.h"
#include "ToughPack.h"

int main()
{
    std::vector<std::shared_ptr<Box>> boxes;
    boxes.push_back(std::make_shared<Box>(20.0, 30.0, 40.0));
    boxes.push_back(std::make_shared<ToughPack>(20.0, 30.0, 40.0));
    boxes.push_back(std::make_shared<Carton>(20.0, 30.0, 40.0, "plastic"));

    for (auto &p : boxes)
        p->showVolume();
}
