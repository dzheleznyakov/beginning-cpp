#ifndef YARDS_H
#define YARDS_H

#include "BaseLength.h"

const double MM_PER_YARD{914.4};

class Yards : public BaseLength
{
public:
    Yards(double value) : BaseLength{value * MM_PER_YARD} {}

    double getValue() const override { return valueMm / MM_PER_YARD; }
    string getUnit() const override { return "yard"; }

    string toString() const override
    {
        const double value{getValue()};
        return std::to_string(value) + (value == 1.0 ? " yard" : " yards");
    }
};

#endif
