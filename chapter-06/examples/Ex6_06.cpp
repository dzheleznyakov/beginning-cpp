// Using smart pointers
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <locale>

using std::shared_ptr;
using std::vector;

int main()
{
    vector<shared_ptr<vector<double>>> records;
    size_t day{1};
    char answer{};
    double t{};

    while (true)
    {
        auto pDay = std::make_shared<vector<double>>();
        records.push_back(pDay);
        std::cout << "Enter the temperature for day " << day++
                  << " separated by spaces. Enter 1000 to end:\n";

        while (true)
        {
            std::cin >> t;
            if (t == 1000.0)
                break;
            pDay->push_back(t);
        }
        std::cout << "Enter another day's temperature (Y or N)? ";
        std::cin >> answer;
        if (toupper(answer) == 'N')
            break;
    }

    double total{};
    size_t count{};
    day = 1;
    std::cout << std::fixed << std::setprecision(2) << std::endl;
    for (auto record : records)
    {
        std::cout << "\nTemperature for day " << day++ << ":\n";
        for (auto temp : *record)
        {
            total += temp;
            std::cout << std::setw(6) << temp;
            if (++count % 5 == 0)
                std::cout << std::endl;
        }
        std::cout << "\nAverage temperature: " << total / count << std::endl;
        total = 0.0;
        count = 0;
    }
}
