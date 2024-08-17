// Defining a class cotructor
#include <iostream>
#include "Box.h"

int main()
{
    Box firstBox{80.0, 50.0, 40.0};
    double firstBoxVolume{firstBox.volume()};
    std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;
}
