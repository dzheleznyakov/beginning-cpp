#include <iostream>
#include <string>
#include "exercise10_02_print.h"

extern int print_count;

void print(const std::string &s)
{
    std::cout << s << std::endl;
    ++print_count;
}
