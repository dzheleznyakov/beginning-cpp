#include "Box.h"

inline bool Box::operator<(const Box &box) const
{
    return volume() < box.volume();
}

inline bool Box::operator<(double aValue) const
{
    return volume() < aValue;
}

inline Box Box::operator+(const Box &aBox) const
{
    return Box{length > aBox.length ? length : aBox.length,
               width > aBox.width ? width : aBox.width,
               height + aBox.height};
}

inline void Box::listBox() const
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
