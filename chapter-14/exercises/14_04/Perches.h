#ifndef PERCHES_H
#define PERCHES_H

#include "BaseLength.h"

const double MM_PER_PERCH{5029.2};

class Perches : public BaseLength
{
public:
    Perches(double value) : BaseLength{value * MM_PER_PERCH} {}
    Perches(const BaseLength &length) : BaseLength{length.getValueMm()} {}

    double getValue() const override { return valueMm / MM_PER_PERCH; }
    string getUnit() const override { return getValue() == 1.0 ? "perch" : "perches"; }
};

#endif
