/*
    Area and perimeter of a rectangle:
    Write a program that displays the area and perimeter of a rectangle
    with a width of 5.3 and height of 8.6.
*/
#include <iostream>

int main()
{
    const double width{5.3};
    const double height{8.6};
    std::cout << "The rectangle has the width " << width << " and height " << height << "."
              << "\nIts perimeter is " << (2 * (width + height))
              << " and its area is " << (width * height) << "."
              << std::endl;
}
