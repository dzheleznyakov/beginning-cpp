// Overloading a function
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

double largest(const double data[], size_t count);
double largest(const vector<double> &data);
int largest(const vector<int> &data);
string largest(const vector<string> &words);

int main()
{
    double values[]{1.5, 44.6, 13.7, 21.2, 6.7};
    vector<int> numbers{15, 44, 13, 21, 6, 8, 5, 2};
    vector<double> data{3.5, 5, 6, -1.2, 8.7, 6.4};
    vector<string> names{
        "Charles Dickens", "Emily Bronte", "Jane Austen",
        "Henry James", "Arthur Miller"};

    std::cout << "The largest of values is "
              << largest(values, sizeof(values) / sizeof(values[0])) << std::endl;
    std::cout << "The largest of numbers is " << largest(numbers) << std::endl;
    std::cout << "The largest of data is " << largest(data) << std::endl;
    std::cout << "The largest of names is " << largest(names) << std::endl;
}

double largest(const double data[], size_t count)
{
    size_t index_max{};
    for (size_t i{1}; i < count; ++i)
        if (data[index_max] < data[i])
            index_max = i;
    return data[index_max];
}

double largest(const vector<double> &data)
{
    double max{data[0]};
    for (auto value : data)
        if (max < value)
            max = value;
    return max;
}

int largest(const vector<int> &data)
{
    int max{data[0]};
    for (auto value : data)
        if (max < value)
            max = value;
    return max;
}

string largest(const vector<string> &words)
{
    string max_word{words[0]};
    for (auto &word : words)
        if (max_word < word)
            max_word = word;
    return max_word;
}
