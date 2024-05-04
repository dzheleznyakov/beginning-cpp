// Failing to modify the original value of a function argument
#include <iostream>
#include <iomanip>

double change_it(double value_to_be_changed);

int main()
{
    double it{5.0};
    double result{change_it(it)};

    std::cout << "After function execution, it = " << it
              << "\nResult returned is " << result << std::endl;
}

double change_it(double it)
{
    it += 10.0;
    std::cout << "Within function, it = " << it << std::endl;
    return it;
}
