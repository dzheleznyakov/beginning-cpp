/*
    Create a vector<> container with elements containing the integers from 1 to 100
    and output the values 6 on a line with the values aligned in columns.
    Output the elements from the vector that contain values that are not multiple
    of 7 or 13. 8 on a line aligned in columns
*/
#include <iomanip>
#include <iostream>
#include <vector>

int main()
{
    std::vector<unsigned int> numbers{
        1, 3, 5, 45, 100, 26, 47, 39, 26, 68, 90, 57, 5, 13, 98,
        76, 67, 90, 23, 24, 97, 75, 34, 2};

    std::cout << "Here are the numbers:\n";
    size_t perline{6};
    size_t line_count{0};
    for (std::vector<unsigned int>::size_type i = 0; i < numbers.size(); ++i)
    {
        std::cout << std::setw(6) << numbers.at(i);
        if (++line_count == perline || i == numbers.size() - 1)
        {
            std::cout << '\n';
            line_count = 0;
        }
    }

    std::cout << "\nHere are the numbers that are not multipliers of 7 or 13:\n";
    perline = 8;
    line_count = 0;
    for (std::vector<unsigned int>::size_type i = 0; i < numbers.size(); ++i)
    {
        unsigned int num{numbers.at(i)};
        if (num % 7 == 0 || num % 13 == 0)
            continue;
        std::cout << std::setw(6) << num;
        if (++line_count == perline || i == numbers.size() - 1)
        {
            std::cout << '\n';
            line_count = 0;
        }
    }

    std::cout << std::endl;
}
