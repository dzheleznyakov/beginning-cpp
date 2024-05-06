// Overloading function templates
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T larger(T a, T b);

template <typename T>
T larger(const T data[], size_t count);

template <typename T>
T larger(const std::vector<T> &data);

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int a_int{35}, b_int{45};
    std::cout << "Larer of " << a_int << " and " << b_int << " is "
              << larger(a_int, b_int) << std::endl;

    long a_long{9L}, b_long{8L};
    std::cout << "Larger of " << a_long << " and " << b_long << " is "
              << larger(a_long, b_long) << std::endl;

    const char text[]{"A nod is as good as a wink to a blind horse."};
    std::cout << "Largest character in \"" << text << "\" is '"
              << larger(text, sizeof(text)) << "'" << std::endl;

    std::vector<std::string> words{"The", "higher", "the", "fewer"};
    std::cout << "The largest word in words is \"" << larger(words)
              << "\"" << std::endl;

    std::vector<double> data{-1.4, 7.3, -100.0, 54.1, 16.3};
    std::cout << "The largest value in data is " << larger(data) << std::endl;
}

template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T larger(const T data[], size_t count)
{
    T result{data[0]};
    for (size_t i{1}; i < count; ++i)
        if (data[i] > result)
            result = data[i];

    return result;
}

template <typename T>
T larger(const std::vector<T> &data)
{
    T result{data[0]};
    for (auto &value : data)
        if (value > result)
            result = value;

    return result;
}
