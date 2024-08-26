// Using the addition operator for Box objects
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Box.h"

using namespace std::rel_ops;

inline double random(double max_size)
{
    return 1 + static_cast<int>(max_size * static_cast<double>(std::rand()) / (RAND_MAX + 1.0));
}

int main()
{
    const double dimLimit{99.0};
    std::srand((unsigned)std::time(0));

    const size_t boxCount{20};
    std::vector<Box> boxes;

    for (size_t i{}; i < boxCount; ++i)
        boxes.push_back(Box{random(dimLimit), random(dimLimit), random(dimLimit)});

    size_t first{};
    size_t second{1};
    double minVolume{(boxes[first] + boxes[second]).volume()};

    for (size_t i{}; i < boxCount - 1; ++i)
        for (size_t j{i + 1}; j < boxCount; ++j)
            if (boxes[i] + boxes[j] < minVolume)
            {
                first = i;
                second = j;
                minVolume = (boxes[i] + boxes[j]).volume();
            }

    std::cout << "The two boxes that sum to the smallest volume are:";
    boxes[first].listBox();
    boxes[second].listBox();
    std::cout << "\nThe volume of the first box is " << boxes[first].volume();
    std::cout << "\nThe volume of the second box is " << boxes[second].volume();
    std::cout << "\nThe box that the sum of these boxes is";
    (boxes[first] + boxes[second]).listBox();
    std::cout << "\nThe volume of the sum is " << minVolume << std::endl;
}
