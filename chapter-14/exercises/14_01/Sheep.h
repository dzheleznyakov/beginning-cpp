#ifndef SHEEP_H
#define SHEEP_H

#include <string>
#include "Animal.h"

using std::string;

class Sheep : public Animal
{
public:
    Sheep(string name, int weight) : Animal(name, weight) {}

    string who() const override { return "Sheep " + Animal::who(); }

    string sound() const override { return "baa"; }
};

#endif
