#include <iostream>

int main() {
    const unsigned int inches_per_feet {12U};
    unsigned int distance {};

    std::cout << "Enter the distance in inches: ";
    std::cin >> distance;

    unsigned int feet {distance / inches_per_feet};
    unsigned int inches {distance % inches_per_feet};

    std::cout << "The distance corresponds to "
              << feet << " feet and "
              << inches << " inches." << std::endl;
}