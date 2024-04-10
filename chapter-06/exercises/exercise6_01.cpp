/*
    Write a program that declares and initialises an array
    with the first 50 even numbers. Output the numbers from the array
    ten to a line using pointer notation, and then output them in reverse order
    also using pointer notation.
*/
#include <iomanip>
#include <iostream>

int main()
{
    const size_t size{50};
    int even_numbers[size];

    for (size_t i{}; i < size; ++i)
        even_numbers[i] = static_cast<int>(2 * (i + 1));

    const int perline{10};
    std::cout << "\nThe first " << size << " even numbers are:" << std::endl;
    for (size_t i{}; i < size; ++i)
    {
        std::cout << std::setw(5) << *(even_numbers + i);
        if ((i + 1) % perline == 0)
            std::cout << std::endl;
    }

    std::cout << "\nThe first " << size << " even numbers in the reverse order are:" << std::endl;
    for (size_t i{}; i < size; ++i)
    {
        std::cout << std::setw(5) << *(even_numbers + size - i - 1);
        if ((i + 1) % perline == 0)
            std::cout << std::endl;
    }
}
