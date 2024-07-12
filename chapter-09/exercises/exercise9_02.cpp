/*
    Define a lambda expression that will multiply the value of a double variable
    that is passed by reference by a scale factor that is defined in the
    enclosing scope. Demonstrate that the lambda works by applying it
    to the elements of a vector.
*/
#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;
using Numbers = vector<double>;

void readNumbers(Numbers &nums);

template <typename F>
void mapNumbers(Numbers &nums, F mapper);

void showNumbers(const Numbers &nums);

int main()
{
    Numbers nums{};
    double scale_factor{3.5};
    readNumbers(nums);
    showNumbers(nums);
    mapNumbers(nums, [&scale_factor](double num) -> double
               { return scale_factor * num; });
    showNumbers(nums);
}

void readNumbers(Numbers &nums)
{
    double num{};
    std::cout << "Enter numbers, or 0 to finish: ";
    while (true)
    {
        std::cin >> num;
        if (!num)
            break;
        nums.push_back(num);
    }
}

void showNumbers(const Numbers &nums)
{
    const size_t max_length = 10;
    const size_t perline = 5;
    std::cout << "Here the current numbers:";
    std::cout << std::left;
    for (size_t i{}; i < nums.size(); ++i)
    {
        if (i % perline == 0)
            std::cout << std::endl;
        std::cout << std::setw(max_length) << nums[i];
    }
    std::cout << std::endl;
}

template <typename F>
void mapNumbers(Numbers &nums, F mapper)
{
    for (size_t i{}; i < nums.size(); ++i)
        nums[i] = mapper(nums[i]);
}
