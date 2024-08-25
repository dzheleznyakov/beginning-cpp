/*
    Change the solution for Exercise 11-02 so that it implements
    the compare() function as a friend of the IntegerN class.
*/
#include <iostream>

#include "Integer.h"

int main()
{
    std::cout << "Trying comparison with Integer1:" << std::endl;
    Integer1 int1_1{};
    Integer1 int1_2{5};
    Integer1 int1_3{int1_2};

    std::cout << "num1 < num2 = " << compare(int1_1, int1_2) << std::endl;
    std::cout << "num2 < num3 = " << compare(int1_2, int1_3) << std::endl;
    std::cout << "num3 < num1 = " << compare(int1_3, int1_1) << std::endl;

    std::cout << std::endl;

    std::cout << "Trying comparison with Integer2:" << std::endl;
    Integer2 int2_1{};
    Integer2 int2_2{5};
    Integer2 int2_3{int2_2};

    std::cout << "num1 < num2 = " << compare(int2_1, int2_2) << std::endl;
    std::cout << "num2 < num3 = " << compare(int2_2, int2_3) << std::endl;
    std::cout << "num3 < num1 = " << compare(int2_3, int2_1) << std::endl;
}
