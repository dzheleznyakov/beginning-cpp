#include <iostream>
#include "exercise10_03_print_this.h"
#include "exercise10_03_print_that.h"

extern int print1_count = 0;
extern int print2_count = 0;

int main()
{
    print_this("This is your kingdom!");
    std::cout << std::endl;
    print_that("That is your kinkdom!");

    std::cout << "The function print1::print() was invoked "
              << print1_count << " times" << std::endl;
    std::cout << "The function print2::print() was invoked "
              << print2_count << " times" << std::endl;
}
