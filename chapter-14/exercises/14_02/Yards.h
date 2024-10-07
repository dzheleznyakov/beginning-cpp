#ifndef YARDS_H
#define YARDS_H

#include "BaseLength.h"

class Yards : public BaseLength
{
private:
    static constexpr double mmInYard{914.4};

public:
    Yards(double value) : BaseLength{value * mmInYard} {}

    double getValue() const override { return valueMm / mmInYard; }
    string getUnit() const override { return "yard"; }
};

#endif
