// Reading the prime file
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using ulong = unsigned long long;

int main()
{
    std::string filename{"output_data/primes.txt"};
    std::ifstream inFile{filename};

    if (!inFile)
    {
        std::cout << "Failed to open the file " << filename << std::endl;
        return 1;
    }

    ulong aprime{};
    size_t count{};
    size_t perline{6};
    while (true)
    {
        inFile >> aprime;
        if (inFile.eof())
            break;

        std::cout << (count++ % perline == 0 ? "\n" : "")
                  << std::setw(10) << aprime;
    }
    std::cout << "\n"
              << count << " primes read from " << filename << std::endl;
}
