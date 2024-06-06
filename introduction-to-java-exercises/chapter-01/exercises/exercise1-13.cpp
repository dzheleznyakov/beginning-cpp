/*
    Algebra: solve 2 x 2 linear equations:
    Use Cramer's rule to solve the following 2 x 2 system
    of linear equation, provided that ad - bc is not 0:
        ax + by = e
        cx + dy = f
        x = (ed - bf) / (ad - bc)
        y = {af - ec} / (ad - bc)
    Write a program to compute the solution and solve the following equation:
        3.4x + 50.2y = 44.5
        2.1x + .55y = 5.9
*/
#include <iostream>

int main()
{
    std::cout << "2 x 2 linear equations:\n"
              << "    ax + by = e\n"
              << "    cx + dy = f\n\n";

    double a{}, b{}, c{}, d{}, e{}, f{};
    std::cout << "Enter a, b and e: ";
    std::cin >> a >> b >> e;
    std::cout << "\nEnter c, d and f: ";
    std::cin >> c >> d >> f;

    double div{a * d - b * c};
    if (div == 0)
    {
        std::cout << "This system does not have a solution. Try again with different equations." << std::endl;
        return 0;
    }

    double x{(e * d - b * f) / div};
    double y{(a * f - c * e) / div};

    std::cout << "The solution is:"
              << "\nx = " << x << ","
              << "\ny = " << y << std::endl;
}
