/*
    Implement function members add(), subtract(), and multiply() for the Integer class
    that will add, subtract, and multiply the current object by the value represented
    by the argument of type Integer. Demonstrate the operation of these functions in your
    class with a version if main() that creates Integer objects encapsulating
    values 4, 5, 6, 7, and 8, and then uses these to calculate the value of
    4 * 5^3 + 6 * 5^2 + 7 * 5 + 8. Implement the functions so that the calculation
    and the output of the result can be performed in a single statement.
*/
#include <iostream>

#include "Integer.h"

int main()
{
    Integer four{4};
    Integer five(5);
    Integer six{6};
    Integer seven{7};
    Integer eight{8};

    std::cout << "4 * 5^3 + 6 * 5^2 + 7 * 5 + 8 = "
              << four.multiply(five).multiply(five).multiply(five).add(six.multiply(five).multiply(five)).add(seven.multiply(five)).add(8).getValue()
              << std::endl;
}
