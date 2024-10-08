#ifndef INCHES_H
#define INCHES_H

#include "BaseLength.h"

const double MM_PER_INCH{25.4};

class Inches : public BaseLength
{
public:
    Inches(double value) : BaseLength{value * MM_PER_INCH}
    {
        std::cout << "double constructor" << std::endl;
    }
    Inches(const BaseLength &length) : BaseLength{length.getValueMm()} {}

    double getValue() const override { return valueMm / MM_PER_INCH; }
    string getUnit() const override { return getValue() == 1.0 ? "inch" : "inches"; }
};

#endif
