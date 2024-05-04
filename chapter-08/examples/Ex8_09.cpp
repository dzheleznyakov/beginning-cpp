// Using multiple default parameter values
#include <iostream>
#include <iomanip>
#include <string>

using std::string;

void show_data(
    const int data[],
    size_t count = 1,
    const string &title = "Data Values",
    size_t width = 10,
    size_t perline = 5);

int main()
{
    int samples[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int dataItem{-99};
    show_data(&dataItem);

    dataItem = 13;
    show_data(&dataItem, 1, "Unlucky for some!");

    show_data(samples, sizeof(samples) / sizeof(samples[0]));
    show_data(samples, sizeof(samples) / sizeof(samples[0]), "Samples");
    show_data(samples, sizeof(samples) / sizeof(samples[0]), "Samples", 6);
    show_data(samples, sizeof(samples) / sizeof(samples[0]), "Samples", 8, 4);
}

void show_data(
    const int data[],
    size_t count,
    const string &title,
    size_t width,
    size_t perline)
{
    std::cout << title << std::endl;

    for (size_t i{}; i < count; ++i)
    {
        std::cout << std::setw(width) << data[i];
        if ((i + 1) % perline == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
