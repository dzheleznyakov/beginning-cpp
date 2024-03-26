/*
    Write a program that outputs the squares of the odd integers
    from 1 up to a limit that is entered by the user.
*/
#include <iostream>
#include <iomanip>

int main()
{
    size_t limit{};
    std::cout << "Enter the max number you want to check (between 1 and 100): ";
    std::cin >> limit;

    if (limit > 100 || limit < 1)
    {
        std::cout << "The number should be between 1 and 100." << std::endl;
        return 0;
    }

    std::cout << "Here are the squares of odd integers up to " << limit << ":"
              << "\n Number   Square "
              << "\n-----------------";
    for (size_t i = 1; i <= limit; i += 2)
    {
        std::cout << "\n"
                  << std::setw(4) << i
                  << std::setw(11) << (i * i);
    }

    std::cout << std::endl;
}