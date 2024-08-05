#include <iostream>
#include <string>
#include "exercise10_01_print_this.h"
#include "exercise10_01_print_that.h"

int main()
{
    std::string s{"This is your kingdom!"};
    print_this(s);
    std::cout << std::endl;
    print_that(s);
}
