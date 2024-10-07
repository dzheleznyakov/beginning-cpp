#ifndef PERCHES_H
#define PERCHES_H

#include "BaseLength.h"

class Perches : public BaseLength
{
private:
    static constexpr double mmInPerch{5029.2};

public:
    Perches(double value) : BaseLength{value * mmInPerch} {}

    double getValue() const override { return valueMm / mmInPerch; }
    string getUnit() const override { return "perch"; }
};

#endif
