#ifndef VESSEL_H
#define VESSEL_H

#include <iostream>

class Vessel
{
public:
    virtual double volume() const = 0;

    virtual ~Vessel() { std::cout << "Vessel destructor." << std::endl; }
};

#endif
