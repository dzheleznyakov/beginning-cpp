#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.h"

using std::string;

class Dog : public Animal
{
public:
    Dog(string name, int weight) : Animal{name, weight} {}

    string who() const override { return "Dog " + Animal::who(); }

    string sound() const override { return "woof"; }
};

#endif
