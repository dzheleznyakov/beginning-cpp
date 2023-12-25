// Allocating an array at runtime
#include <iostream>

int main()
{
    size_t count{};
    std::cout << "How many heights will you enter? ";
    std::cin >> count;
    unsigned int height[count];

    size_t entered{};
    while (entered < count)
    {
        std::cout << "Enter a height: ";
        std::cin >> height[entered];
        if (height[entered])
        {
            ++entered;
        }
        else
        {
            std::cout << "A height must be positive - try again.\n";
        }
    }

    unsigned int total{};
    for (size_t i = 0; i < count; ++i)
    {
        total += height[i];
    }
    std::cout << "The average height is " << (total / count) << std::endl;
}