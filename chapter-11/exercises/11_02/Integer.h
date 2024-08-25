#ifndef INTEGER_11_02
#define INTEGER_11_02

#include <iostream>

class Integer1
{
private:
    int value;

public:
    Integer1(int val) : value{val}
    {
        std::cout << "Integer1 int constructor invoked." << std::endl;
    }

    Integer1() : value{}
    {
        std::cout << "Integer1 no-arg constructor invoked." << std::endl;
    }

    Integer1(Integer1 &num) : value{num.value}
    {
        std::cout << "Integer1 copy constructor invoked." << std::endl;
    }

    int compare(const Integer1 other)
    {
        if (value < other.value)
            return -1;
        if (value == other.value)
            return 0;
        return 1;
    }
};

class Integer2
{
private:
    int value;

public:
    Integer2(int val) : value{val}
    {
        std::cout << "Integer2 int constructor invoked." << std::endl;
    }

    Integer2() : value{}
    {
        std::cout << "Integer2 no-arg constructor invoked." << std::endl;
    }

    Integer2(Integer2 &num) : value{num.value}
    {
        std::cout << "Integer2 copy constructor invoked." << std::endl;
    }

    int compare(const Integer2 &other)
    {
        if (value < other.value)
            return -1;
        if (value == other.value)
            return 0;
        return 1;
    }
};

#endif
