#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Person.h"

using std::string;

class Employee : public Person
{
private:
    int personnelNumber;

public:
    Employee(string name, int age, string gender, int pnv)
        : Person{age, name, gender}, personnelNumber{pnv} {}

    Employee(const Employee &employee)
        : Person{employee}, personnelNumber{employee.personnelNumber} {}

    int getPersonnelNumber() const { return personnelNumber; }

    string who() const
    {
        return getName() + " (" + getGender() + ") is an Employee";
    }
};

#endif
