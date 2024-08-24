#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <iomanip>

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}

    Box() {}

    Box(const Box &box) : length{box.length}, width{box.width}, height{box.height} {}

    double volume() const
    {
        return length * width * height;
    }

    int compare(const Box &box)
    {
        if (volume() < box.volume())
            return -1;
        if (volume() == box.volume())
            return 0;
        return 1;
    }

    void listBox()
    {
        std::cout << " Box(" << std::setw(2) << length << ","
                  << std::setw(2) << width << ","
                  << std::setw(2) << height << ")";
    }
};

#endif
