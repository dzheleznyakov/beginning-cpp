/*
    Repeat the calculations in Exercise 6-2 but using a vector<> container
    allocated in the free store. Test the progra with more than 100,000 elements.
    Do you notice anything interesting about the result?
*/
#include <iostream>
#include <memory>
#include <vector>

int main()
{
    size_t size{};
    std::cout << "Enter the number of the elements to process: ";
    std::cin >> size;

    auto values = std::make_shared<std::vector<double>>();
    for (size_t i{}; i < size; ++i)
    {
        values->push_back(1.0 / (i + 1) / (i + 1));
    }

    double sum{};
    for (size_t i{}; i < size; ++i)
    {
        sum += values->at(i);
    }

    std::cout << "The result is " << std::sqrt(sum * 6) << std::endl;
}
