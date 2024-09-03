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
    double thickness{0.125};
    double density{0.3};

public:
    Carton(double lv, double wv, double hv, const string desc) : Box{lv, wv, hv}, material(desc)
    {
        std::cout << "Carton(double, double, double, string) is called.\n";
    }

    Carton(const string desc) : material{desc}
    {
        std::cout << "Carton(string) is called.\n";
    }

    Carton(const Carton &carton) : Box{carton}, material{carton.material}
    {
        std::cout << "Carton(Carton) is called.\n";
    }

    Carton(double side, const string desc) : Box{side}, material{desc}
    {
        std::cout << "Carton(double, string) is called.\n";
    }

    Carton(double lv, double wv, double hv, const string desc, double dense, double thick)
        : Carton{lv, wv, hv, desc}
    {
        density = dense;
        thickness = thick;
        std::cout << "Carton(double, double, double, string, double, double) is called.\n";
    }

    Carton()
    {
        std::cout << "Carton() is called.\n";
    }

    ~Carton()
    {
        std::cout << "Carton destructor. Material = " << material << "." << std::endl;
    }

    double getWeight() const
    {
        return 2.0 * (length * width + width * height + height * length) * density * thickness;
    }
};

#endif
