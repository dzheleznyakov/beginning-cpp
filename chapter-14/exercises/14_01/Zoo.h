#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <vector>
#include <string>
#include "Animal.h"

using std::string;
using std::vector;

class Zoo
{
private:
    vector<Animal *> pAnimals;

public:
    Zoo() {}

    void addAnimal(Animal *pAnimal)
    {
        pAnimals.push_back(pAnimal);
    }

    vector<string> whoIsInZoo() const
    {
        vector<string> report;
        for (auto p : pAnimals)
            report.push_back(p->who() + ", says " + p->sound());
        return report;
    }

    void printResidentsReport() const
    {
        std::cout << "The following animals live in the zoo:" << std::endl;
        for (auto p : pAnimals)
            std::cout << p->who() << std::endl;
    }

    void printResidentsSounds() const
    {
        std::cout << "The animals of the zoo say the following:" << std::endl;
        for (auto p : pAnimals)
            std::cout << p->getName() << " say \"" + p->sound() << "\"" << std::endl;
    }

    ~Zoo()
    {
        std::cout << "Cleaning up Zoo." << std::endl;
        std::cout << pAnimals.size() << " animals." << std::endl;
        for (auto p : pAnimals)
            delete p;
    }
};

#endif
