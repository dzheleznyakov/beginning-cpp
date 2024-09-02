#ifndef CARTON_H
#define CARTON_H

#include <string>

#include "Box.h"

using std::string;

class Carton : public Box
{
private:
    string material;

public:
    Carton(const string desc = "Cardboard") : material{desc} {}
};

#endif
