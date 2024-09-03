#ifndef CONTENTS_H
#define CONTENTS_H

#include <iostream>
#include <string>

using std::string;

class Contents
{
protected:
    string name{"cereal"};
    double volume{};
    double unitWeight{0.03};

public:
    Contents(const string name, double wt, double vol)
        : name{name}, unitWeight{wt}, volume{vol}
    {
        std::cout << "Conents(string, double, double) is called.\n";
    }

    Contents(const string name) : name{name}
    {
        std::cout << "Contents(string) is called.\n";
    }

    ~Contents()
    {
        std::cout << "Contents destructor." << std::endl;
    }

    double getWeight() const
    {
        return volume * unitWeight;
    }
};

#endif
