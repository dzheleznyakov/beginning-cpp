// Writing primes to a file
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using ulong = unsigned long long;

int main()
{
    size_t max{};
    std::cout << "How many primes would you like (at least 4)? : ";
    std::cin >> max;
    if (max < 4)
        max = 4;

    std::vector<ulong> primes{2ULL, 3ULL, 5ULL};
    ulong trial{5ULL};
    bool isprime{false};
    ulong limit{};

    while (primes.size() < max)
    {
        trial += 2;
        limit = static_cast<ulong>(std::sqrt(trial));
        for (auto prime : primes)
        {
            if (prime > limit)
                break;
            isprime = trial % prime > 0;
            if (!isprime)
                break;
        }
        if (isprime)
            primes.push_back(trial);
    }

    std::string filename{"output_data/primes.txt"};
    std::ofstream outFile{filename};

    size_t perline{5};
    size_t count{};
    for (auto prime : primes)
    {
        outFile << std::setw(10) << prime;
        if (++count % perline == 0)
            outFile << std::endl;
    }
    outFile << std::endl;
    std::cout << max << " primes written to " << filename << std::endl;
}
