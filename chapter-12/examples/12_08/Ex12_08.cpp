// Using the subscript operator on the left of an assignment
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Truckload.h"

inline double random(double max_size)
{
    return 1 + static_cast<int>(max_size * static_cast<double>(std::rand()) / (RAND_MAX + 1.0));
}

inline ptr<Box> randomBox(double max_size)
{
    return std::make_shared<Box>(random(max_size), random(max_size), random(max_size));
}

int main()
{
    const double dimLimit{99.0};
    std::srand((unsigned)std::time(0));
    Truckload load;
    const size_t boxCount{20};

    for (size_t i{}; i < boxCount; ++i)
        load.addBox(randomBox(dimLimit));

    std::cout << "The boxes are:\n";
    std::cout << load;

    double maxVolume{};
    size_t maxIndex{};
    size_t i{};
    while (load[i])
    {
        if (load[i]->volume() > maxVolume)
        {
            maxIndex = i;
            maxVolume = load[i]->volume();
        }
        ++i;
    }

    std::cout << "\nThe largest box is:";
    std::cout << *load[maxIndex] << std::endl;

    load.deleteBox(load[maxIndex]);
    std::cout << "\nAfter deleting the largest box, the list contains:\n";
    std::cout << load << std::endl;

    load[0] = load[1];
    std::cout << "\nAfter copying the 2nd element to the 1st, the list contains:\n"
              << load;

    load[1] = std::make_shared<Box>(*load[2] + *load[3]);
    std::cout << "\nAfter making the 2nd element a pointer to the 3rd plus 4th,"
              << " the list contains:\n"
              << load;
}
