#ifndef COW_H
#define COW_H

#include <string>
#include "Animal.h"

using std::string;

class Cow : public Animal
{
public:
    Cow(string name, int weight) : Animal{name, weight} {};

    string who() const override { return "Cow " + Animal::who(); }

    string sound() const override { return "moo"; }
};

#endif
