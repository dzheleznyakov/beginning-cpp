/*
    Write a program that reads an array size from the keyboard
    an dynamically allocates an array of that size
    to hold floating-point values. Using pointer notation,
    initialize all the elements of the array
    so that the value of the element at index position n is
    1.0/(n+1)^2. Calculate the sum of the elements using pointer notation,
    multiply the sum by 6, and ouput the square root of that result.
*/
#include <cmath>
#include <iostream>

int main()
{
    size_t size{};
    std::cout << "Enter the number of the elements to process: ";
    std::cin >> size;

    double *array{new double[size]};
    for (size_t i{}; i < size; ++i)
    {
        *(array + i) = 1.0 / (i + 1) / (i + 1);
    }

    double sum{};
    for (size_t i{}; i < size; ++i)
    {
        sum += *(array + i);
    }

    std::cout << "The result is " << std::sqrt(sum * 6) << std::endl;
}
