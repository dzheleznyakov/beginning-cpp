// Generating multiplication tables
#include <iostream>
#include <iomanip>
#include <locale>

int main()
{
    size_t table{};
    const size_t table_min{2};
    const size_t table_max{12};
    char reply{};

    do
    {
        std::cout << "What size table would you like ("
                  << table_min << " to " << table_max << ")? ";
        std::cin >> table;
        std::cout << std::endl;

        if (table < table_min || table > table_max)
        {
            std::cout << "Invalid table size entered. Program terminated." << std::endl;
            return 1;
        }

        std::cout << std::setw(6) << " |";
        for (size_t i{1}; i <= table; ++i)
        {
            std::cout << " " << std::setw(3) << i << " |";
        }
        std::cout << std::endl;

        for (size_t i{}; i <= table; ++i)
        {
            std::cout << "------";
        }
        std::cout << std::endl;

        for (size_t i{1}; i <= table; ++i)
        {
            std::cout << " " << std::setw(3) << i << " |";

            for (size_t j{1}; j <= table; ++j)
            {
                std::cout << " " << std::setw(3) << i * j << " |";
            }
            std::cout << std::endl;
        }

        std::cout << "\nDo you want another table? (y or n)? ";
        std::cin >> reply;
    } while (tolower(reply == 'y'));
}
