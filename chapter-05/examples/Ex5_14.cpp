// Sorting an array in ascending sequence - using a vector<T> container
#include <iostream>
#include <iomanip>
#include <vector>
using std::vector;

int main()
{
    vector<double> x;
    double temp{};

    while (true)
    {
        std::cout << "Enter a non-zero value, or 0 to end: ";
        std::cin >> temp;

        if (!temp)
            break;

        x.push_back(temp);
    }

    std::cout << "Starting sort." << std::endl;

    bool swapped{false};
    while (true)
    {
        for (vector<double>::size_type i{}; i < x.size() - 1; ++i)
        {
            if (x.at(i) > x.at(i + 1))
            {
                temp = x.at(i);
                x.at(i) = x.at(i + 1);
                x.at(i + 1) = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
    }

    std::cout << "Your data in ascending sequence:\n"
              << std::fixed << std::setprecision(1);
    const size_t perline{10};
    size_t n{};
    for (vector<double>::size_type i{}; i < x.size(); ++i)
    {
        std::cout << std::setw(8) << x[i];
        if (++n == perline)
        {
            std::cout << std::endl;
            n = 0;
        }
    }
    std::cout << std::endl;
}