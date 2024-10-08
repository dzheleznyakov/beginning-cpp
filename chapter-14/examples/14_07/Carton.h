#ifndef CARTON_H
#define CARTON_H

#include <string>
#include "Box.h"

using std::string;

class Carton : public Box
{
private:
    string material;

public:
    Carton(double lv, double wv, double hv, string str = "cardboard")
        : Box{lv, wv, hv}
    {
        material = str;
    }

    double volume() const
    {
        double vol{(length - 0.5) * (width - 0.5) * (height - 0.5)};
        return vol > 0.0 ? vol : 0.0;
    }
};

#endif
