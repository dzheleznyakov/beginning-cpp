// Debugging using preprocessing derectives
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "functions.h"

using std::cout;
using std::endl;

#define TESTINDEX

size_t random(size_t count)
{
    return static_cast<size_t>(
        count * static_cast<unsigned long>(std::rand()) / (RAND_MAX + 1UL));
}

int main()
{
    int a{10}, b{5};
    int result{};

    int (*pfun[])(int, int){fun::sum, fun::product, fun::difference};
    size_t fcount{sizeof pfun / sizeof pfun[0]};
    size_t select{};
    srand(static_cast<unsigned>(time(0)));

    for (size_t i{}; i < 10; ++i)
    {
        select = random(fcount);
#ifdef TESTINDEX
        std::cout << "Random number = " << select;
        if (select >= fcount || select < 0)
        {
            std::cout << "Invalid array index = " << select << std::endl;
            return 1;
        }
#endif
        result = pfun[select](a, b);
        std::cout << " result = " << result << std::endl;
    }
    result = pfun[1](pfun[0](a, b), pfun[2](a, b));
    std::cout << "The product of the sum and the difference = " << result << std::endl;
}
