#include <iostream>

int main() {
    double radius {};
    const double PI {3.14159265};

    std::cout << "Enter the radius of a circle: ";
    std::cin >> radius;

    double area {PI * radius * radius};

    std::cout << "The area of a circle with radius " << radius
              << " is " << area << std::endl;
}