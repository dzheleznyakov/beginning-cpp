// Exercising pointers to functions
#include <iostream>

long sum(long a, long b);
long product(long a, long b);

int main()
{
    long (*pDo_it)(long, long){};

    pDo_it = product;
    std::cout << "3*5 = " << pDo_it(3, 5) << std::endl;

    pDo_it = sum;
    std::cout << "3 * (4 + 5) + 6 = "
              << pDo_it(product(3, pDo_it(4, 5)), 6) << std::endl;
}

long sum(long a, long b)
{
    return a + b;
}

long product(long a, long b)
{
    return a * b;
}
