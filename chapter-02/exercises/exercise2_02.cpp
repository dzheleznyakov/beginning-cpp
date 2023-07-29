#include <iostream>
#include <iomanip>

int main() {
    double radius {};
    const double PI {3.14159265};

    std::cout << "Enter the radius of a circle: ";
    std::cin >> radius;

    double area {PI * radius * radius};

    unsigned int precision {};
    std::cout << "Enter the answer's precision: ";
    std::cin >> precision;

    std::cout << "The area of a circle with radius " << radius
              << " is " << std::fixed << std::setprecision(precision) << area << std::endl;
}