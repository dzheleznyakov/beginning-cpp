/*
    Print a table:
    Write a program that displays a certain table.
*/
#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::left;
    std::cout << std::setw(6) << "a"
              << std::setw(6) << "a^2"
              << std::setw(6) << "a^3"
              << std::setw(6) << "a^4"
              << std::endl;
    std::cout << std::setw(6) << 1
              << std::setw(6) << 1
              << std::setw(6) << 1
              << std::setw(6) << 1
              << std::endl;
    std::cout << std::setw(6) << 2
              << std::setw(6) << 4
              << std::setw(6) << 8
              << std::setw(6) << 16
              << std::endl;
    std::cout << std::setw(6) << 3
              << std::setw(6) << 9
              << std::setw(6) << 27
              << std::setw(6) << 81
              << std::endl;
    std::cout << std::setw(6) << 4
              << std::setw(6) << 16
              << std::setw(6) << 64
              << std::setw(6) << 256
              << std::endl;
}
