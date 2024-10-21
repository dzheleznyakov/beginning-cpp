#ifndef BOX_H
#define BOX_H

#include <algorithm>
#include "dimension_error.h"

class Box
{
protected:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv}
    {
        if (lv <= 0.0 || wv <= 0.0 || hv <= 0.0)
            throw dimension_error{"Zero or negative box dimensions.", std::min(lv, std::min(wv, hv))};
    }

    double volume() const { return length * width * height; }
};

#endif
