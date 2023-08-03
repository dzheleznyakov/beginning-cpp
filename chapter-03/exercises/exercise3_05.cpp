#include <iostream>

int main() {
    int a {}, b {};
    std::cout << "Enter two integers (a and b): ";
    std::cin >> a >> b;

    a = a - b;
    b = a + b;
    a = b - a;
    std::cout << "Now the values are swapped, so a = " << a << " and b = " << b << std::endl;
}