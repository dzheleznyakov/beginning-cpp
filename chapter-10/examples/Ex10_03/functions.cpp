// #define TESTFUNCTIONS

#ifdef TESTFUNCTIONS
#include <iostream>
#endif

#include "functions.h"

int fun::sum(int x, int y)
{
#ifdef TESTFUNCTIONS
    std::cout << "Function sum called." << std::endl;
#endif

    return x + y;
}

int fun::product(int x, int y)
{
#ifdef TESTFUNCTIONS
    std::cout << "Function product called." << std::endl;
#endif

    return x * y;
}

int fun::difference(int x, int y)
{
#ifdef TESTFUNCTIONS
    std::cout << "Function difference called." << std::endl;
#endif

    return x - y;
}
