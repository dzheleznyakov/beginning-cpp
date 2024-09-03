#ifndef CARTON_H
#define CARTON_H

#include <iostream>
#include <string>

#include "Box.h"

using std::string;

class Carton : public Box
{
private:
    string material{"Cardboard"};

public:
    Carton(double lv, double wv, double hv, string desc) : Box{lv, wv, hv}, material(desc)
    {
        std::cout << "Carton(double, double, double, string) is called.\n";
    }

    Carton(string desc) : material{desc}
    {
        std::cout << "Carton(string) is called.\n";
    }

    Carton(double side, string desc) : Box{side}, material{desc}
    {
        std::cout << "Carton(double, string) is called.\n";
    }

    Carton()
    {
        std::cout << "Carton() is called.\n";
    }
};

#endif
