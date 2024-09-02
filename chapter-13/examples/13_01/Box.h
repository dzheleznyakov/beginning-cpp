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

    Box() = default;

    double volume() const
    {
        return length * width * height;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    friend std::ostream &operator<<(std::ostream &stream, const Box &box)
    {
        stream << "Box(" << std::setw(2) << box.length << ","
               << std::setw(2) << box.width << ","
               << std::setw(2) << box.height << ")";
        return stream;
    }
};

#endif
