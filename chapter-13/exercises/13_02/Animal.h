#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using std::string;

class Animal
{
private:
    string name;
    int weight;

public:
    Animal(const string nv, int wv) : name{nv}, weight{wv} {}

protected:
    string who() const
    {
        return name + " has weight " + std::to_string(weight) + " pounds";
    }
};

#endif
