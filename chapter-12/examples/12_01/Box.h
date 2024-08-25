#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}

    Box() {};

    Box(const Box &box) : length{box.length}, width{box.width}, height{box.height} {}

    double volume() const
    {
        return length * width * height;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    bool operator<(const Box &aBox) const
    {
        return volume() < aBox.volume();
    }
};

#endif
