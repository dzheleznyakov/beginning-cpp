// Modifying the value of a caller variable
#include <iostream>

double change_it(double *pointer_to_it);

int main()
{
    double it{5.0};
    double result{change_it(&it)};

    std::cout << "After function execution, it = " << it
              << "\nResult returned is " << result << std::endl;
}

double change_it(double *pit)
{
    *pit += 10.0;
    std::cout << "Within function, *pit = " << *pit << std::endl;
    return *pit;
}
