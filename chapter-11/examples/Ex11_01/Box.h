#ifndef BOX_H
#define BOX_H

class Box
{
private:
    double length{0.1};
    double width{1.0};
    double height{1.0};

public:
    Box(double lengthValue, double widthValue, double heightValue);
    Box();

    double volume();
};

#endif
