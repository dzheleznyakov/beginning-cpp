#ifndef INCHES_H
#define INCHES_H

#include "BaseLength.h"

class Inches : public BaseLength
{
private:
    static constexpr double mmPerInch{25.4};

public:
    Inches(double value) : BaseLength{value * mmPerInch} {}

    double getValue() const override { return valueMm / mmPerInch; }
    string getUnit() const override { return "inch"; }
};

#endif
