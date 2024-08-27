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

Box Box::operator*(int n) const
{
    return Box{length, width, height * n};
}

void Box::listBox() const
{
    std::cout << " Box(" << std::setw(2) << length << ","
              << std::setw(2) << width << ","
              << std::setw(2) << height << ")";
}

std::ostream &operator<<(std::ostream &stream, const Box &box)
{
    stream << " Box(" << std::setw(2) << box.length << ","
           << std::setw(2) << box.width << ","
           << std::setw(2) << box.height << ")";
    return stream;
}

Box operator*(int n, const Box &box)
{
    return Box{box.length, box.width, box.height * n};
}
