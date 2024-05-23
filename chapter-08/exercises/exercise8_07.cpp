/*
    Define a function to comptue Ackerman's function recursively.
    Test the function for values of n between 0 and 5, and m between 0 and 3.
    One particular property of this function is that the depth of recursion.
*/
#include <iomanip>
#include <iostream>

void printTests(int maxM, int maxN);
int ack(int m, int n);

int main()
{
    printTests(3, 5);
}

void printHeader(int maxM, size_t width, size_t first_width)
{
    std::cout << std::setw(first_width) << "m-> |";
    std::cout << std::setw(first_width) << "\nn   | ";
    std::cout << std::setw(first_width) << "\n|   | ";
    std::cout << std::setw(first_width) << "\n˅   | ";
    for (size_t m{}; m <= maxM; ++m)
        std::cout << std::setw(width) << m;
    std::cout << std::endl;
    for (size_t i{}; i <= first_width + (maxM + 1) * width; ++i)
        std::cout << '-';
}

void printTests(int maxM, int maxN)
{
    std::cout << std::left;
    const size_t first_width{6};
    const size_t width = 10;
    printHeader(maxM, width, first_width);
    for (size_t n{}; n <= maxN; ++n)
    {
        std::cout << '\n'
                  << std::setw(first_width - 2)
                  << n << "| ";
        for (size_t m{}; m <= maxM; ++m)
        {
            std::cout << std::setw(width) << ack(m, n);
        }
    }
    std::cout << std::endl;
}

int ack(int m, int n)
{
    if (m == 0)
        return n + 1;

    if (n == 0)
        return ack(m - 1, 1);

    return ack(m - 1, ack(m, n - 1));
}
