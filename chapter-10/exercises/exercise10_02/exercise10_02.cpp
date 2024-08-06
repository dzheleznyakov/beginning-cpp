#include <iostream>
#include "exercise10_02_print_this.h"
#include "exercise10_02_print_that.h"

extern int print_count = 0;

int main()
{
    print_this("This is your kingdom!");
    print_that("That is your kinkdom!");

    std::cout << "The function print() was invoked "
              << print_count << " times" << std::endl;
}
