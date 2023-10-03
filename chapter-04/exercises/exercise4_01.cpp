#include <iostream>

int main() {
    int num1 {};
    int num2 {};

    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    if (num1 == num2) {
        std::cout << "These two integers are the same.";
    } else {
        std::cout << "These two integers are different.";
    }
    std::cout << std::endl;
}