/*
    The famous Fibonacci series is a sequence of itnegers with the first two values as 1
    and the subsequent values as the sum of the two preceeding values.
    Create an array<> container with 90 elements. Store the first 90 numbers
    in the Fibonacci series in the array, then output the 5 to a line, aligned in columns.
*/
#include <array>
#include <iomanip>
#include <iostream>

int main()
{
    const size_t size{90};
    std::array<long long int, size> fibs{};
    fibs[0] = 1;
    fibs[1] = 1;
    for (size_t i{2}; i < size; ++i)
        fibs[i] = fibs[i - 2] + fibs[i - 1];

    const size_t perline{5};
    size_t in_line_count{0};
    std::cout << "Here are the first " << size << " Fibonacci numbers: " << std::left;
    for (auto fib : fibs)
    {
        if (in_line_count == 0)
            std::cout << '\n';
        std::cout << std::setw(22) << fib;
        if (++in_line_count == perline)
            in_line_count = 0;
    }
    std::cout << std::endl;
}