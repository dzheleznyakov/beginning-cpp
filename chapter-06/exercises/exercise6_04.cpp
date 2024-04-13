/*
    You know that a two-dimensinal array is an "array of arrays".
    You also know that you can create an array dynamically using a pointer.
    If the elements of the array that you create dynamically
    are also pointers, then each element in the array could store the address
    of an array. Using this concept, create an array of three pointers to arrays,
    in which each array can store six values of type int.
    Set the first array of integers to values 1 to 6,
    the next array to the squares (N x N) of the values stores
    in the first array, and the next the cubes (N x N x N) of the values stored
    in the first array of integers.
    Output the contents of the three arrays, and then delete the memory
    you've allocated.
*/

#include <cmath>
#include <iomanip>
#include <iostream>

using std::shared_ptr;

int main()
{
    const size_t n_arrays{3};
    const size_t dimensions{6};
    auto arrays = new int *[n_arrays];
    for (size_t i{}; i < n_arrays; ++i)
        arrays[i] = new int[dimensions];

    for (size_t i{}; i < n_arrays; ++i)
    {
        for (size_t j{}; j < dimensions; ++j)
        {
            arrays[i][j] = std::pow(j + 1, i + 1);
        }
    }

    std::cout << "The values in the arrays are:\n";
    for (size_t i{}; i < n_arrays; ++i)
    {
        for (size_t j{}; j < dimensions; ++j)
        {
            std::cout << std::setw(5) << arrays[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (size_t i{}; i < n_arrays; ++i)
        delete[] arrays[i];
    delete[] arrays;
}
