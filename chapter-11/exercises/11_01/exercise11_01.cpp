/*
    Create a class called Integer that has a single, private
    data member of type int. Provide a class constructor
    that outputs a message when an object is created. Define function
    members to get and set the data member, and to output its value.
    Write a test program to create and manipulate at least three Integer objects,
    and verify that you can't assign a value directly to the data member.
    Exercise all the class function members by getting, setting, and outputting
    the value of the data member of each object.
*/
#include <iostream>
#include "Integer.h"

void increase(Integer &int_n)
{
    int_n.setValue(int_n.getValue() + 1);
}

int main()
{
    Integer int1{5};
    Integer int2{};
    Integer int3{int1};

    std::cout << "\nint1 value is " << int1.getValue() << std::endl;
    std::cout << "int2 value is " << int2.getValue() << std::endl;
    std::cout << "int3 value is " << int3.getValue() << std::endl;

    increase(int1);
    increase(int2);
    int3.setValue(42);
    std::cout << "\nAfter resetting values:";
    std::cout << "\nint1 value is " << int1.getValue() << std::endl;
    std::cout << "int2 value is " << int2.getValue() << std::endl;
    std::cout << "int3 value is " << int3.getValue() << std::endl;
}
