// Sparce array template
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SparseArray.h"

size_t random(size_t count)
{
    return static_cast<size_t>(
        count * static_cast<unsigned long>(std::rand()) / (RAND_MAX + 1UL));
}

int main()
{
    std::srand((unsigned)std::time(0));
    SparseArray<int> array{};
    for (size_t i{}; i < 20; ++i)
        array[random(499)] = 32 + static_cast<int>(random(180));
    std::cout << array << std::endl;
}
