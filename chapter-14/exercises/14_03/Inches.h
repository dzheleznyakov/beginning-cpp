#ifndef INCHES_H
#define INCHES_H

#include "BaseLength.h"

const double MM_PER_INCH{25.4};

class Inches : public BaseLength
{
public:
    Inches(double value) : BaseLength{value * MM_PER_INCH} {}

    double getValue() const override { return valueMm / MM_PER_INCH; }
    string getUnit() const override { return "inch"; }

    string toString() const override
    {
        double value{getValue()};
        return std::to_string(value) + (value == 1.0 ? " inch" : " inches");
    }
};

#endif
