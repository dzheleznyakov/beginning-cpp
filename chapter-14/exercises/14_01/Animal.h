#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using std::string;

class Animal
{
protected:
    string name;
    int weight;

    Animal(string n, int w) : name{n}, weight{w} {}

public:
    virtual string who() const { return name + ", " + std::to_string(weight) + " pounds"; }

    virtual string sound() const = 0;

    virtual ~Animal() { std::cout << "Animal destructor." << std::endl; }

    string getName() const
    {
        return name;
    }
};

#endif
