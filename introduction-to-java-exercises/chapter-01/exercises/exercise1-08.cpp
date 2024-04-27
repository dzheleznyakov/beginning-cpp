/*
    Area and perimeter of a circle:
    Write a program that displays the area and perimeter of a circle
    that has a radius of 6.5.
*/
#include <iostream>

int main()
{
    const double radius{6.5};
    const double pi{3.14159};
    std::cout << "The area of a circle of radius " << radius << " is "
              << (radius * radius * pi)
              << "\nThe perimeter of a circle of radius " << radius << " is "
              << (2 * radius * pi)
              << std::endl;
}
