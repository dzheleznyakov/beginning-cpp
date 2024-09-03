#ifndef CEREALPACK_H
#define CEREALPACK_H

#include <iostream>
#include <string>
#include "Carton.h"
#include "Contents.h"

using std::string;

class CerealPack : public Carton, public Contents
{
public:
    CerealPack(double length, double width, double height, const string cerealType)
        : Carton{length, width, height, "cardboard"}, Contents{cerealType}
    {
        std::cout << "CerealPack(double, double, double, string) is called.\n";
        Contents::volume = 0.9 * Carton::volume();
    }

    ~CerealPack()
    {
        std::cout << "CerealPack destructor." << std::endl;
    }
};

#endif
