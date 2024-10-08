#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
protected:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}

    void showVolume() const
    {
        std::cout << "Box usable volume is " << volume() << std::endl;
    }

    double volume() const { return length * width * height; }
};

#endif
