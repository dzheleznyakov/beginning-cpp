#include <iostream>

int main() {
    unsigned int a {}, b {};

    std::cout << "Enter two different positive integers: ";
    std::cin >> a >> b;

    unsigned int larger {(a * (a / b) + b * (b / a)) / ( a / b + b / a)};
    unsigned int smaller {a + b - larger};

    std::cout << "The larger number is " << larger
              << " and the smaller number is " << smaller << std::endl;
}