#include <iostream>
#include <string>
#include "exercise10_04_print.h"
#include "exercise10_04_print_this.h"

void print_this(const std::string &s)
{
    std::cout << "Printing this string:" << std::endl;
    print1::print(s);
}
