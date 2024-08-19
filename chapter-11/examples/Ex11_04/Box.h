#ifndef BOX_H
#define BOX_H

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv = 1.0, double wv = 1.0, double hv = 1.0);

    double volume();

    friend double surfaceArea(const Box &aBox);
};

#endif
