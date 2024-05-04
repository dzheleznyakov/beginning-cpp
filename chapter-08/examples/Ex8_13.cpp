// Overloading a function with reference parameters
#include <iostream>

double larger(double a, double b);
long &larger(long &a, long &b);

int main()
{
    double a_double{1.5}, b_double{2.5};
    std::cout << "The larger of double values "
              << a_double << " and " << b_double << " is "
              << larger(a_double, b_double) << std::endl;

    int a_int{15}, b_int{25};
    std::cout << "The larger of int values "
              << a_int << " and " << b_int << " is "
              << larger(static_cast<long>(a_int), static_cast<long>(b_int))
              << std::endl;
}

double larger(double a, double b)
{
    std::cout << "double larger() called." << std::endl;
    return a > b ? a : b;
}

long &larger(long &a, long &b)
{
    std::cout << "long ref larger() called." << std::endl;
    return a > b ? a : b;
}
