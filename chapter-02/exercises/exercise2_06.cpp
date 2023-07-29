#include <iostream>

int main() {
    const double lbs_per_kilo {2.2};
    const double meters_per_foot {0.3048};
    const unsigned int inches_per_foot {12U};

    double weight_in_lbs {};
    unsigned int height_feet {}, height_inches {};

    std::cout << "Enter your weight in pounds: ";
    std::cin >> weight_in_lbs;
    std::cout << "Enter you height in feet and inches: ";
    std::cin >> height_feet >> height_inches;
    
    const double height_in_feet {height_feet + height_inches / static_cast<double>(inches_per_foot)};
    const double heignt_in_meters {height_in_feet * meters_per_foot};
    const double weight_in_kilos {weight_in_lbs / lbs_per_kilo};
    const double bmi {weight_in_kilos / (heignt_in_meters * heignt_in_meters)};

    std::cout << "Your BMI is " << bmi << std::endl;
}