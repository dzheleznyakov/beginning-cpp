#include <iostream>
#include <locale>

int main () {
    int num {};
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "The number you entered is "
              << (
        num <= 20 ? "20 or less" :
        num <= 30 ? "greater than 20 and not greater than 30" :
        num <= 100 ? "greater than 30 and not greater than 100" :
        "greater than 100"
    )
        << std::endl;
}