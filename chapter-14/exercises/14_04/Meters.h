#ifndef METERS_H
#define METERS_H

#include "BaseLength.h"

const double MM_PER_METER{1000.0};

class Meters : public BaseLength
{
public:
    Meters(double value) : BaseLength{value * MM_PER_METER} {}
    Meters(const BaseLength &length) : BaseLength{length.getValueMm()} {}

    double getValue() const override { return valueMm / MM_PER_METER; }
    string getUnit() const override { return getValue() == 1.0 ? "meter" : "meters"; }
};

#endif
