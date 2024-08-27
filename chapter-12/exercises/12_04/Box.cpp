#include <vector>

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

size_t Box::operator/(const Box &box) const
{
    auto divider = [this](double l, double w, double h) -> size_t
    {
        size_t rows{static_cast<size_t>(this->length / l)};
        size_t columns{static_cast<size_t>(this->width / w)};
        size_t layers{static_cast<size_t>(this->height / h)};
        return rows * columns * layers;
    };
    std::vector<size_t> candidates{
        divider(box.length, box.width, box.height),
        divider(box.length, box.height, box.width),
        divider(box.width, box.length, box.height),
        divider(box.width, box.height, box.length),
        divider(box.height, box.width, box.length),
        divider(box.height, box.length, box.width)};
    size_t result = 0;
    for (size_t i{}; i < candidates.size(); ++i)
        if (candidates[i] > result)
            result = candidates[i];
    return result;
}

double Box::operator%(const Box &box) const
{
    size_t n{(*this) / box};
    return this->volume() - n * box.volume();
}

void Box::listBox() const
{
    std::cout << *this;
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
