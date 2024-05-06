// Recursive version of function for x to the power n, n positive or negative
#include <iostream>
#include <iomanip>

double power(double x, int n);

int main()
{
    for (int i{-3}; i <= 3; ++i)
        std::cout << std::setw(10) << power(8.0, i);

    std::cout << std::endl;
}

double power(double x, int n)
{
    if (!n)
        return 1.0;
    if (n > 0)
        return x * power(x, n - 1);
    return 1.0 / power(x, -n);
}
