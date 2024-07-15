/*
    Define and demonstrate a recursive lambda expression that
    accepts an unsigned integer as an argument and returns an integer
    that corresponds to the argument with its decimal digits reversed.
*/
#include <iostream>
#include <functional>

int main()
{
    unsigned int num{};
    std::cout << "Enter an integer number: ";
    std::cin >> num;
    unsigned int reversedNum{};

    std::function<unsigned int(unsigned int)> reverse =
        [&reverse, &reversedNum](unsigned int n) mutable -> unsigned int
    {
        if (n == 0)
            return reversedNum;
        unsigned int digit{n % 10};
        reversedNum = reversedNum * 10 + digit;
        return reverse(n / 10);
    };

    std::cout << "The number '" << num << "' reversed is " << reverse(num) << std::endl;
}
