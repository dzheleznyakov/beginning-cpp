/*
    Modify the constructor for the Integer class in the exercise 11_01 so that
    the data member is initialized to zero in the constructor initialization
    list and implement a copy constructor. Add a function member that
    compares the current object with an Integer object passed as an argument.
    The function should return -1 if the current object is less than the argumen,
    0 if the objects are equal, and +1 if the current object is greater than the argument.
    Try two versions of the Integer class, one where the compare () function
    argument is passed by value and the other where it is passed by reference.
    What do you see output from the constructors when the function is called?
*/
#include <iostream>

#include "Integer.h"

int main()
{
    std::cout << "Trying comparison with Integer1:" << std::endl;
    Integer1 int1_1{};
    Integer1 int1_2{5};
    Integer1 int1_3{int1_2};

    std::cout << "num1 < num2 = " << int1_1.compare(int1_2) << std::endl;
    std::cout << "num2 < num3 = " << int1_2.compare(int1_3) << std::endl;
    std::cout << "num3 < num1 = " << int1_3.compare(int1_1) << std::endl;

    std::cout << std::endl;

    std::cout << "Trying comparison with Integer2:" << std::endl;
    Integer2 int2_1{};
    Integer2 int2_2{5};
    Integer2 int2_3{int2_2};

    std::cout << "num1 < num2 = " << int2_1.compare(int2_2) << std::endl;
    std::cout << "num2 < num3 = " << int2_2.compare(int2_3) << std::endl;
    std::cout << "num3 < num1 = " << int2_3.compare(int2_1) << std::endl;
}
