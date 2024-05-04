// Using static variables
#include <iostream>
#include <iomanip>

long next_Fibonacci();

int main()
{
    size_t count{};
std:
    std::cout << "Enter the number of Fibonacci values to be generated: ";
    std::cin >> count;
    std::cout << "The Fibonacci series:\n";
    for (size_t i{}; i < count; ++i)
    {
        std::cout << std::setw(10) << next_Fibonacci();
        if (!((i + 1) % 8))
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

long next_Fibonacci()
{
    static long last;
    static long last_but_one{1L};

    long next{last + last_but_one};
    last_but_one = last;
    last = next;
    return last;
}
