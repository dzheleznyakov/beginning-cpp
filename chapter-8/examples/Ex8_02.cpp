// Calculating powers - rearranged
#include <iostream>
#include <iomanip>

int main()
{
    for (int i{-3}; i <= 3; ++i)
        std::cout << std::setw(10) << power(8.0, i);
    std::cout << std::endl;
}

double power(double x, int n)
{
    double result{1.0};
    if (n >= 0)
        for (int i{}; i < n; ++i)
            result *= x;
    else
        for (int i{}; i < -n; ++i)
            result /= x;
    return result;
}
