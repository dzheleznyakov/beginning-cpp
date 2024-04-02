// Calculating primes using dynamic memory allocation
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    size_t max{};
    size_t count{3};

    std::cout << "How many primes would you like? ";
    std::cin >> max;

    unsigned long long *primes{new unsigned long long[max]};
    *primes = 2uLL;
    *(primes + 1) = 3uLL;
    *(primes + 2) = 5uLL;
    unsigned long long trial{*(primes + 2)};
    bool isprime{false};

    unsigned long long limit{};
    do
    {
        trial += 2;
        limit = static_cast<unsigned long long>(std::sqrt(trial));
        size_t i{};
        do
        {
            isprime = trial % *(primes + i) > 0;
        } while (primes[++i] <= limit && isprime);

        if (isprime)
            *(primes + count++) = trial;
    } while (count < max);

    for (size_t i{}; i < max; ++i)
    {
        std::cout << std::setw(10) << *(primes + i);
        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
    delete[] primes;
    primes = nullptr;
}
