#ifndef TOUGHPACK_H
#define TOUGHPACK_H

#include "Box.h"

class ToughPack : public Box
{
public:
    ToughPack(double lv, double wv, double hv) : Box{lv, wv, hv} {}

    double volume() const override { return 0.85 * length * width * height; }
};

#endif