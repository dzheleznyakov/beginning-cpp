#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Employee.h"

using std::string;

class Executive : public Employee
{
public:
    Executive(string name, int age, string gender, int personnelNumber)
        : Employee{name, age, gender, personnelNumber} {}

    Executive(const Executive &executive) : Employee{executive} {}

    string who() const
    {
        return getName() + " (" + getGender() + ") is a Director";
    }
};

#endif