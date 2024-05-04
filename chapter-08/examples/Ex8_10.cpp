// Returning a pointer
#include <iostream>
#include <iomanip>
#include <string>

using std::string;

void show_data(
    const double data[],
    size_t count = 1,
    const string &title = "Data Values",
    size_t width = 10,
    size_t perline = 5);
const double *largest(const double data[], size_t count);
const double *smallest(const double data[], size_t count);
double *shift_range(double data[], size_t count, double delta);
double *scale_range(double data[], size_t count, double divisor);
double *normalize_range(double data[], size_t count);

int main()
{
    double samples[]{
        11.0, 23.0, 13.0, 4.0,
        57.0, 36.0, 317.0, 88.0,
        9.0, 100.0, 121.0, 12.0};

    const size_t count{sizeof(samples) / sizeof(samples[0])};
    show_data(samples, count, "Original Values");
    normalize_range(samples, count);
    show_data(samples, count, "Normalized Values", 12);
}

const double *largest(const double data[], size_t count)
{
    size_t index_max{};
    for (size_t i{1}; i < count; ++i)
        if (data[index_max] < data[i])
            index_max = i;
    return &data[index_max];
}

const double *smallest(const double data[], size_t count)
{
    size_t index_min{};
    for (size_t i{1}; i < count; ++i)
        if (data[index_min] > data[i])
            index_min = i;
    return &data[index_min];
}

double *shift_range(double data[], size_t count, double delta)
{
    for (size_t i{}; i < count; ++i)
        data[i] += delta;
    return data;
}

double *scale_range(double data[], size_t count, double divisor)
{
    if (!divisor)
        return data;

    for (size_t i{}; i < count; ++i)
        data[i] /= divisor;
    return data;
}

double *normalize_range(double data[], size_t count)
{
    return scale_range(
        shift_range(data, count, -(*smallest(data, count))),
        count,
        *largest(data, count));
}

void show_data(
    const double data[],
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
