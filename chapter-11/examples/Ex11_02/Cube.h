#ifndef CUBE_H
#define CUBE_H

class Cube
{
public:
    double side;

    /* explicit */ Cube(double side);
    double volume();
    bool compareVolume(Cube aCube);
};

#endif
