#ifndef BOX_H
#define BOX_H

class Volume
{
public:
    static double operator()(double x, double y, double z)
    {
        return x * y * z;
    }
};

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box() : length{1.0}, width{1.0}, height{1.0} {}

    Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}

    Box(const Box &box) : length{box.length}, width{box.width}, height{box.height} {};

    double volume()
    {
        Volume volume;
        return Volume::(length, width, height);
    }
};

#endif