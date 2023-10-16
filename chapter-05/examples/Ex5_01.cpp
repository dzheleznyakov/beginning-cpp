// Using a for-loop with an array
#include <iostream>

int main()
{
    const size_t size {6};
    unsigned int height[size] {26, 37, 47, 55, 62, 75};
    unsigned int total {};

    for (size_t i {}; i < size; ++i)
    {
        total += height[i];
    }

    int average {static_cast<int>(total / size)};
    std::cout << "The average hight is " << average << std::endl;
    
    unsigned int count {};
    for (size_t i = 0; i < size; ++i)
    {
        if (height[i] < average) ++count;
    }
    std::cout << count << " people are below average height." << std::enl;
}