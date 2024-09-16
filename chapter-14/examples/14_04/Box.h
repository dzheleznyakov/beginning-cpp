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
        double vol{volume()};
        std::cout << "Box usable volume is " << vol << std::endl;
    }

    virtual double volume(int i = 5) const
    {
        std::cout << "Box parameter = " << i << std::endl;
        return length * width * height;
    }
};

#endif
