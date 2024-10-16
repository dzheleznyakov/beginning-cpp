#ifndef BASE_LENGTH_H
#define BASE_LENGTH_H

#include <iostream>
#include <string>

using std::string;

class BaseLength
{
protected:
    double valueMm;

    BaseLength(double value) : valueMm{value} {}

public:
    double getValueMm() const { return valueMm; }

    virtual double getValue() const = 0;
    virtual string getUnit() const = 0;

    friend std::ostream &operator<<(std::ostream &stream, const BaseLength &length);
};

#endif