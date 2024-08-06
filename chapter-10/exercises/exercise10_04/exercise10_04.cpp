#include <iostream>
#include "exercise10_04_print_this.h"
#include "exercise10_04_print_that.h"

extern int print1_count = 0;
extern int print2_count = 0;

#define DO_THIS

int main()
{
#ifdef DO_THIS
    print_this("This is your kingdom!");
#else
    print_that("That is your kinkdom!");
#endif

    std::cout << "The function print1::print() was invoked "
              << print1_count << " times" << std::endl;
    std::cout << "The function print2::print() was invoked "
              << print2_count << " times" << std::endl;
}
