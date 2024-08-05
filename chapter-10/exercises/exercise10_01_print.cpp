#include <iostream>
#include <string>
#include "exercise10_01.h"

using std::string;

void print(const string &s)
{
    std::cout << s << std::endl;
}

void print_this(const string &s)
{
    std::cout << "Printing this string:" << std::endl;
    print(s);
}

void print_that(const string &s)
{
    std::cout << "Printing that string:" << std::endl;
    print(s);
}
