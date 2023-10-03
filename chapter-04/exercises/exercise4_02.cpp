#include <iostream>

int main() {
    int n {};
    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> n;

    if (n >=1 && n <= 100) {
        if (n < 50) {
            std::cout << "The number is less than 50";
        } else if (n > 50) {
            std::cout << "The number is greater than 50";
        } else {
            std::cout << "The number is equal to 50";
        }
    } else {
        std::cout << "The number you entered is outside of the required range.";
    }
    std::cout << std::endl;
}