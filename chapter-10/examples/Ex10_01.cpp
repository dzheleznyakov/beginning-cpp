// Using a namespace and a header file
#include <iostream>
#include <string>
#include "Ex10_01.h"

namespace data
{
    extern const double pi;
    extern const std::string days[];
}

int main()
{
    std::cout << "pi has the value " << data::pi << std::endl;
    std::cout << "The second day of the week is " << data::days[1] << std::endl;
}
