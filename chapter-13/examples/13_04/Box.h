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
    Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
    {
        std::cout << "Box(double, double, double) is called.\n";
    }

    Box(double side) : Box{side, side, side}
    {
        std::cout << "Box(double) is called.\n";
    }

    Box(const Box &box) : length{box.length}, width{box.width}, height{box.height}
    {
        std::cout << "Box(Box) is called.\n";
    }

    Box()
    {
        std::cout << "Box() is called.\n";
    }

    ~Box()
    {
        std::cout << "Box destructor" << std::endl;
    }

    double volume() const
    {
        return length * width * height;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

#endif
