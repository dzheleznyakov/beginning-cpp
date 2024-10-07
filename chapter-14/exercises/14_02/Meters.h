#ifndef METERS_H
#define METERS_H

#include "BaseLength.h"

class Meters : public BaseLength
{
private:
    static constexpr double mmInMeter{1000.0};

public:
    Meters(double value) : BaseLength{value * mmInMeter} {}

    double getValue() const override { return valueMm / mmInMeter; }
    string getUnit() const override { return "meter"; }
};

#endif
