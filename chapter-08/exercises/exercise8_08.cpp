/*
    Define a function template to Quicksort a vector
    of numerical values of any type. Demonstrate
    its typical use for types float and long long.
*/
#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;

template <typename T>
void sort(vector<T> &pnumbers);

template <typename T>
void sort(vector<T> &pnumbers, size_t start, size_t end);

template <typename T>
void swap(vector<T> &pnumbers, size_t first, size_t second);

template <typename T>
void print(const vector<T> &pnumbers);

int main()
{
    vector<int> numsI{
        23, 45, 3, 67, 1, -15, 56, 3434, 3, 0, 76};
    vector<float> numsF{
        32.4F, 4.5F, 0.0F, 45.3F, 983.545F, 784.543F, -34.5F, 90.32F, 56.7F};
    vector<long long> numsLL{
        4LL, 8347934845LL, 456LL, -567LL, 23LL, 1090LL, 45678LL, 3509LL};

    sort(numsI);
    sort(numsF);
    sort(numsLL);

    std::cout << "The sorted vector of integers is:" << std::endl;
    print(numsI);

    std::cout << "The sorted vector of floats is:" << std::endl;
    print(numsF);

    std::cout << "The sorted vector of long longs is:" << std::endl;
    print(numsLL);
}

template <typename T>
void sort(vector<T> &pnumbers)
{
    sort(pnumbers, 0, pnumbers.size() - 1);
}

template <typename T>
void sort(vector<T> &pnumbers, size_t start, size_t end)
{
    if (start >= end)
        return;

    swap(pnumbers, start, (start + end) / 2);

    size_t current{start};
    for (size_t i{start + 1}; i <= end; ++i)
    {
        if (pnumbers[i] < pnumbers[start])
            swap(pnumbers, ++current, i);
    }

    swap(pnumbers, start, current);
    if (current > start)
        sort(pnumbers, start, current - 1);
    if (end > current + 1)
        sort(pnumbers, current + 1, end);
}

template <typename T>
void swap(vector<T> &pnumbers, size_t first, size_t second)
{
    T temp{pnumbers[first]};
    pnumbers[first] = pnumbers[second];
    pnumbers[second] = temp;
}

template <typename T>
void print(const vector<T> &pnumbers)
{
    const size_t perline{5};
    const size_t width{16};
    std::cout << std::left;
    for (size_t i{}; i < pnumbers.size(); ++i)
    {
        if (i % perline == 0)
            std::cout << std::endl;
        std::cout << std::setw(width) << pnumbers[i];
    }
    std::cout << std::endl;
}
