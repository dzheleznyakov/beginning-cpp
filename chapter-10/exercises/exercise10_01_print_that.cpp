#include <iostream>
#include <string>
#include "exercise10_01_print.h"
#include "exercise10_01_print_that.h"

void print_that(const std::string &s)
{
    std::cout << "Printing that string:" << std::endl;
    print(s);
}
