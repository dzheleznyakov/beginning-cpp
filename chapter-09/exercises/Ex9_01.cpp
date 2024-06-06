// Using lambda expressions
#include <iostream>
#include <vector>
#include <string>

using std::string;

int main()
{
    auto cube = [](double value) -> double
    { return value * value * value; };
    double x{2.5};
    std::cout << x << " cubed is " << cube(x) << std::endl;

    auto average = [](const std::vector<double> &v) -> double
    {
        double sum{};
        for (const auto &x : v)
            sum += x;
        return sum / v.size();
    };
    std::vector<double> data{
        1.5, 2.5, 3.5, 4.5, 5.5};
    std::cout << "Average of values in data is " << average(data) << std::endl;

    auto reverse = [](string &input)
    {
        size_t i{};
        size_t j{input.length() - 1};
        while (i < j)
        {
            auto temp{input[i]};
            input[i] = input[j];
            input[j] = temp;
            ++i;
            --j;
        }
    };
    string original{"ma is as selfless as I am"};
    string copy{original};
    reverse(copy);
    std::cout << "\"" << original << "\" reversed is \"" << copy << "\"" << std::endl;
}
