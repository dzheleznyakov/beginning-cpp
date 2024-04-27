/*
    Approximate Pi:
    Pi can be computed using the following formula:
    Pi = 4 x (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...).
    Write a program that displays the result of the formula
    up to 1/11 and 1/13. Use 1.0 instead of 1 in the program.
*/
#include <iostream>

int main()
{
    std::cout << "Approximation of π:"
              << "\n4 x (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11) = "
              << (4 * (1.0 - 1.0 / 3 + 1.0 / 5 - 1.0 / 7 + 1.0 / 9 - 1.0 / 11))
              << "\n4 x (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13) = "
              << (4 * (1.0 - 1.0 / 3 + 1.0 / 5 - 1.0 / 7 + 1.0 / 9 - 1.0 / 11 + 1.0 / 13))
              << std::endl;
}
