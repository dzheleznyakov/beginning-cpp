#ifndef BOX_H
#define BOX_H

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv, double wv, double hv);
    explicit Box(double side);
    Box() {}

    double volume();
};

#endif
