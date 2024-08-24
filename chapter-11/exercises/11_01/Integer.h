#ifndef INTEGER_H_11_01
#define INTEGER_H_11_01

#include <iostream>

class Integer
{
private:
    int value;

public:
    Integer() : value{}
    {
        std::cout << "Integer no-arg constructor invoked." << std::endl;
    }

    Integer(int val) : value{val}
    {
        std::cout << "Integer constructor invoked." << std::endl;
    };

    void setValue(int val)
    {
        value = val;
    }

    int getValue()
    {
        return value;
    }
};

#endif
