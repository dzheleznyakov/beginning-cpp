#include <iostream>
#include <iomanip>

int main() {
    unsigned int num {};
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    unsigned int inverted_num {~num};

    std::cout << "You entered value     : " << num << std::endl
              << "                        " << std::hex << std::setfill('0') << std::setw(8) << num << std::endl
              << "Inverted value plus 1 : " << std::dec << (inverted_num + 1) << std::endl
              << "                        " << std::hex << std::setw(8) << (inverted_num + 1) << std::endl;
}