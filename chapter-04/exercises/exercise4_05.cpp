#include <iostream>

int main() {
    float ammount_in_dollars {};
    std::cout << "Enter an amount of money between $0 and $10: $";
    std::cin >> ammount_in_dollars;

    if (ammount_in_dollars < 0 || ammount_in_dollars > 10) {
        std::cout << "You entered a wrong ammount." << std::endl;
        return 0;
    }
    
    int ammount_in_cents {static_cast<int>(ammount_in_dollars * 100)};
    ammount_in_dollars = ammount_in_cents / 100.0;
    int number_of_quaters {ammount_in_cents / 25};
    ammount_in_cents = ammount_in_cents % 25;
    int number_of_dimes {ammount_in_cents / 10};
    ammount_in_cents = ammount_in_cents % 10;
    int number_of_nickles {ammount_in_cents / 5};
    int number_of_pennies {ammount_in_cents % 5};

    std::cout << "You entered $" << ammount_in_dollars << ". This is";
    if (number_of_quaters > 0) {
        std::cout << "\n  " << number_of_quaters << (number_of_quaters == 1 ? " quater" : " quaters");
    }
    if (number_of_dimes > 0) {
        std::cout << "\n  " << number_of_dimes << (number_of_dimes == 1 ? " dime" : " dimes");
    }
    if (number_of_nickles > 0) {
        std::cout << "\n  " << number_of_nickles << (number_of_nickles == 1 ? " nickle" : " nickles");
    }
    if (number_of_pennies > 0 || (number_of_quaters == 0 && number_of_dimes == 0 && number_of_nickles == 0)) {
        std::cout << "\n  " << number_of_pennies << (number_of_pennies == 1 ? " pence" : " pennies");
    }

    std::cout << std::endl;
}