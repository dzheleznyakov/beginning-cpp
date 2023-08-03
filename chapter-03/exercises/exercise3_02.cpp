#include "iostream"

int main() {
    const unsigned int inches_per_foot {12U};
    unsigned int box_side_in_inches {};
    double shelf_length_in_feet {}, shelf_depth_in_feet {};

    std::cout << "Enter the box side size in inches: ";
    std::cin >> box_side_in_inches;
    std::cout << "Enter the shelf lenght and depth in feet: ";
    std::cin >> shelf_length_in_feet >> shelf_depth_in_feet;

    unsigned int shelf_lenght_in_inches {static_cast<unsigned int>(shelf_length_in_feet * inches_per_foot)};
    unsigned int shelf_depth_in_inches {static_cast<unsigned int>(shelf_depth_in_feet * inches_per_foot)};
    
    unsigned int rows {shelf_lenght_in_inches / box_side_in_inches};
    unsigned int columns {shelf_depth_in_inches / box_side_in_inches};

    std::cout << "You can place " << (rows * columns) << " on this shelf." << std::endl;
}