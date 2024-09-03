#ifndef AARDVARK_H
#define AARDVARK_H

#include <string>
#include "Animal.h"

using std::string;

class Aardvark : public Animal
{
public:
    Aardvark(string name, int weight) : Animal{name, weight} {}
};

#endif
