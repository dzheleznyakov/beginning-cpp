#ifndef LION_H
#define LION_H

#include <string>
#include "Animal.h"

using std::string;

class Lion : public Animal
{
public:
    Lion(const string name, int weight) : Animal{name, weight} {}
};

#endif
