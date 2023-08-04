// Comparing data values
#include <iostream>

int main()
{
    char first {};
    char second {};

    std::cout << "Enter a character: ";
    std::cin >> first;

    std::cout << "Enter a second character: ";
    std::cin >> second;

    std::cout << "The value of the expression " << first << '<' << second
              << " is: " << std::boolalpha << (first < second) << std::endl;
    std::cout << "The value of the expression " << first << "==" << second
              << " is: " << (first == second) << std::endl;
}