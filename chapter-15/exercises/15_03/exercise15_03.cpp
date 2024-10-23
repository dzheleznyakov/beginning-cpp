#include <iostream>
#include <cstdlib>
#include "CurveBall.h"
#include "TooManyExceptions.h"

size_t random(size_t count)
{
    return static_cast<size_t>(
        count * static_cast<unsigned long>(std::rand()) / (RAND_MAX + 1UL));
}

void terminateHandler()
{
    std::cout << "Way too many exceptions thrown." << std::endl;
    std::exit(1);
}

int main()
{
    std::set_terminate(terminateHandler);
    srand(static_cast<unsigned>(time(0)));
    size_t error_count{};
    for (size_t i{}; i < 1000; ++i)
    {
        try
        {
            size_t num = random(20);
            bool shouldThrow{num < 5};
            if (shouldThrow)
                throw CurveBall{};
        }
        catch (CurveBall &ex)
        {
            ++error_count;
            if (error_count > 10)
                throw TooManyExceptions{};
        }
    }
    std::cout << error_count << " errors were thrown." << std::endl;
}
