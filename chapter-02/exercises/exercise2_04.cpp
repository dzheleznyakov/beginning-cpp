#include <iostream>
#include <cmath>

int main() {
    unsigned int distance_feet {};
    unsigned int distance_inches {};
    unsigned int height_in_inches {};
    int angle_in_degrees {};

    std::cout << "Enter the distance to the tree in feet and inches: ";
    std::cin >> distance_feet >> distance_inches;

    std::cout << "Enter the height of your eyesight in inches: ";
    std::cin >> height_in_inches;

    std::cout << "Enter the angle of a tree in degrees: ";
    std::cin >> angle_in_degrees;

    const unsigned int INCHES_PER_FEET {12U};
    const double PI {3.14159265};

    const unsigned int distance_in_inches {distance_feet * INCHES_PER_FEET + distance_inches};
    const double angle_in_radians {2 * PI * angle_in_degrees / 360};
    const unsigned int tree_height_in_inches {
        static_cast<unsigned int>(height_in_inches + distance_in_inches * std::tan(angle_in_radians))
    };

    const unsigned int tree_height_feet {tree_height_in_inches / INCHES_PER_FEET};
    const unsigned int tree_height_inches {tree_height_in_inches % INCHES_PER_FEET};

    std::cout << "The tree height is " 
              << tree_height_feet << " feet and " 
               << tree_height_inches << " inches." << std::endl;
}