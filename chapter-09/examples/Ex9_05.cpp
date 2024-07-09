// Recursive calls in lambda expression
#include <iostream>
#include <functional>

int main()
{
    std::function<long long(long long, long long)> hcf =
        [&hcf](long long i, long long j) mutable -> long long
    {
        if (i < j)
            return hcf(j, i);
        long long remainder{i % j};
        if (!remainder)
            return j;
        return hcf(j, remainder);
    };

    auto showHCF = [&hcf](long long a, long long b)
    {
        std::cout << "The highst common factor of " << a << " and " << b
                  << " is " << hcf(a, b) << std::endl;
    };

    long long a{}, b{};
    while (true)
    {
        std::cout << "\nEnter tow integers to find their HCF, or 0 to end: ";
        std::cin >> a;
        if (!a)
            break;
        std::cin >> b;

        showHCF(a, b);
    }
}
