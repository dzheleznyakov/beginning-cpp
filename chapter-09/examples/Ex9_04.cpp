// Using lambda expressions in function templates
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>

using std::vector;

template <typename T>
void setValues(vector<T> &vec, std::function<void(T &)> fun)
{
    for (size_t i{}; i < vec.size(); ++i)
    {
        fun(vec[i]);
    }
}

template <typename T>
void listVector(const vector<T> &vec)
{
    int count{};
    const int valuesPerLine{5};
    auto print = [&count, valuesPerLine](T value)
    {
        std::cout << std::setw(10) << value << "  ";
        if (++count % valuesPerLine == 0)
            std::cout << std::endl;
    };
    for (size_t i{}; i < vec.size(); ++i)
        print(vec[i]);
}

int main()
{
    vector<int> integerData(50);
    int current{1};
    int increment{1};
    setValues<int>(integerData, [increment, &current](int &v) mutable
                   { v = current + increment++;
                   current = v; });
    std::cout
        << "Integer vector contains: " << std::endl;
    listVector(integerData);

    vector<double> values(10);
    size_t power{};
    double x{2.5};
    setValues<double>(values, [power, x](double &v) mutable
                      { v = std::pow(x, power++); });
    std::cout << "\nDouble vector contains: " << std::endl;
    listVector(values);
}
