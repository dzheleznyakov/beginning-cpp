#include <iostream>
#include <string>
#include "exercise10_04_print.h"

extern int print1_count;
extern int print2_count;

namespace print1
{
    void print(const std::string &s)
    {
        std::cout << "print1: " << s << std::endl;
        ++print1_count;
    }
}

namespace print2
{
    void print(const std::string &s)
    {
        std::cout << "print2: " << s << std::endl;
        ++print2_count;
    }
}
