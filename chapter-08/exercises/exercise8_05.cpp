/*
    Write a function that returns a reference to the smaller
    of two arguments of type long. Write another function that returns
    a reference to the larger of two arguments of type long.
    Use these functions to generate as many numbers of
    the Fibonacci sequence as the user requests.
*/
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

using Fibonacchis = std::shared_ptr<std::vector<long>>;

void generateSequence(Fibonacchis pFibs, const size_t count_limit);
long &smaller(long &n1, long &n2);
long &larger(long &n1, long &n2);
void printSequence(const Fibonacchis pFibs);

int main()
{
    size_t count_limit{};
    std::cout << "How many Fibonacci numbers to generate? ";
    std::cin >> count_limit;
    if (count_limit <= 0)
    {
        std::cout << "No Fibonacci numbers are to be displayed." << std::endl;
        return 0;
    }

    Fibonacchis pFibs = std::make_shared<std::vector<long>>();
    generateSequence(pFibs, count_limit);
    printSequence(pFibs);
}

void generateSequence(Fibonacchis pFibs, const size_t count_limit)
{
    long n1{1}, n2{1};
    size_t count{1};
    pFibs->push_back(n1);
    while (count++ < count_limit)
    {
        pFibs->push_back(larger(n1, n2));
        smaller(n1, n2) = n1 + n2;
    }
}

long &smaller(long &n1, long &n2)
{
    return n1 < n2 ? n1 : n2;
}

long &larger(long &n1, long &n2)
{
    return n1 > n2 ? n1 : n2;
}

void printSequence(Fibonacchis pFibs)
{
    long largest{pFibs->back()};
    const size_t max_size{static_cast<size_t>(std::ceil(std::log10(largest))) + 1 + 2};
    const size_t perline{5};

    size_t line_count{};
    std::cout << "Here are the first " << pFibs->size() << " Fibonacci numbers:";
    std::cout << std::left;
    for (auto num : *pFibs)
    {
        if (line_count++ % perline == 0)
            std::cout << std::endl;
        std::cout << std::setw(max_size) << num;
    }
    std::cout << std::endl;
}
