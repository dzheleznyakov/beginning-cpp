// Writing floating-point properties to cout
#include <iostream>
#include <cfloat>

int main()
{
    std::cout << "The mantissa for type float has " << FLT_MANT_DIG << " bits." << std::endl;
    std::cout << "The maximum value for type float is " << FLT_MAX << "." << std::endl;
    std::cout << "The minimum non-zero value of type float is " << FLT_MIN << "." << std::endl;
}