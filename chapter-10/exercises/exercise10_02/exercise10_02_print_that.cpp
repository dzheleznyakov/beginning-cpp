#include <iostream>
#include <string>
#include "exercise10_02_print.h"
#include "exercise10_02_print_that.h"

void print_that(const std::string &s)
{
    std::cout << "Printing that string:" << std::endl;
    print(s);
}
