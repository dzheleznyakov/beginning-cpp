#ifndef INTEGER_11_04
#define INTEGER_11_04

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

    friend int compare(const Integer1 one, const Integer1 another);
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

    friend int compare(const Integer2 &one, const Integer2 &another);
};

#endif
