#ifndef METERS_H
#define METERS_H

#include "BaseLength.h"

const double MM_PER_METER{1000.0};

class Meters : public BaseLength
{
public:
    Meters(double value) : BaseLength{value * MM_PER_METER} {}

    double getValue() const override { return valueMm / MM_PER_METER; }
    string getUnit() const override { return "meter"; }

    string toString() const override
    {
        const double value{getValue()};
        return std::to_string(value) + (value == 1.0 ? " meter" : " meters");
    }
};

#endif
