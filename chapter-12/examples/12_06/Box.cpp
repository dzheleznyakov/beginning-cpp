#include "Box.h"

bool Box::operator<(const Box &box) const
{
    return volume() < box.volume();
}

bool Box::operator<(double aValue) const
{
    return volume() < aValue;
}

Box Box::operator+(const Box &aBox) const
{
    return Box{length > aBox.length ? length : aBox.length,
               width > aBox.width ? width : aBox.width,
               height + aBox.height};
}

void Box::listBox() const
{
    std::cout << " Box(" << std::setw(2) << length << ","
              << std::setw(2) << width << ","
              << std::setw(2) << height << ")";
}
