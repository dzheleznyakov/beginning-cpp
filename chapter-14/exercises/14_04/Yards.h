#ifndef YARDS_H
#define YARDS_H

#include "BaseLength.h"

const double MM_PER_YARD{914.4};

class Yards : public BaseLength
{
public:
    Yards(double value) : BaseLength{value * MM_PER_YARD} {}
    Yards(const BaseLength &length) : BaseLength{length.getValueMm()} {}

    double getValue() const override { return valueMm / MM_PER_YARD; }
    string getUnit() const override { return getValue() == 1.0 ? "yard" : "yards"; }
};

#endif
