/*
    Define devision for Box objects so that box1 / box2 results in an integer
    that is the number of times box2 can be contained in box1. All instances of
    box2 in box1 must have the same orientation (i.e. all box2 lengths, widths and
    heights parallel) but box2 can be in any orientation relative to box1
    (e.g. box2 width does not have to be parallel to the box1 width).
*/
#include <iostream>

#include "Box.h"

int main()
{
    Box box1{2.0, 2.0, 3.0};
    Box box2{1.0, 1.0, 1.0};
    Box box3{2.0, 2.0, 1.0};
    Box box4{2.0, 1.0, 2.0};

    std::cout << "box1 =" << box1 << ", box2 =" << box2 << ", box3 =" << box3
              << ", box4 =" << box4
              << "\nbox1 / box2 = " << (box1 / box2)
              << "\nbox1 / box3 = " << (box1 / box3)
              << "\nbox1 / box4 = " << (box1 / box4)
              << "\nbox2 / box1 = " << (box2 / box1) << std::endl;
    std::cout << "(box1 + 2 * box2) / box3 = " << (box1 + 2 * box2) / box3 << std::endl;
}
