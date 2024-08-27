#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <iomanip>
#include <algorithm>

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv, double wv, double hv)
        : length{std::max(lv, wv)}, width{std::min(lv, wv)}, height{hv} {}

    Box() = default;

    Box(const Box &box)
        : length{box.length}, width{box.width}, height{box.height} {}

    double volume() const
    {
        return length * width * height;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    bool operator<(const Box &box) const;
    bool operator<(double aValue) const;
    Box operator+(const Box &aBox) const;
    Box operator*(int n) const;
    size_t operator/(const Box &box) const;
    double operator%(const Box &box) const;

    void listBox() const;

    friend std::ostream &operator<<(std::ostream &stream, const Box &box);
    friend Box operator*(int n, const Box &box);
};

#endif
