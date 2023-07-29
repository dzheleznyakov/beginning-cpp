// Converting distances
#include <iostream>

int main() {
    unsigned int yards {}, feet {}, inches {};

    // Convert a distance in yards, feet, and inches to inches
    std::cout << "Enter a distance as yards, feet and inches "
              << "with three values separated by spaces: "  
              << std::endl;
    std::cin >> yards >> feet >> inches;

    const unsigned feet_per_yard {3U};
    const unsigned inches_per_foot {12U};

    unsigned int total_inches {};
    total_inches = inches + inches_per_foot * (feet_per_yard * yards + feet);

    std::cout << "The distances correspond to " << total_inches << " inches." << std::endl;

    // Convert a distance in inches to yards, feet, and inches
    std::cout << "Enter a distance in inches: ";
    std::cin >> total_inches;
    
    feet = total_inches / inches_per_foot;
    inches = total_inches % inches_per_foot;
    yards = feet / feet_per_yard;
    feet = feet % feet_per_yard;

    std::cout << "The distance corresponds to "
              << yards << " yards "
              << feet << " feet "
              << inches << " inches." << std::endl;
}