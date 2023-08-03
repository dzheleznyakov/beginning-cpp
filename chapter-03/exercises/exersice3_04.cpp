#include <iostream>
#include <bitset>
#include <limits>

int main() {
    // int num = std::numeric_limits<int>::max();
    // std::cout << std::bitset<32>(num) << std::endl;
    char ch1 {}, ch2 {}, ch3 {}, ch4 {};
    std::cout << "Enter 4 characters: ";
    std::cin >> ch1 >> ch2 >> ch3 >> ch4;

    int storage = 0;
    storage |= ch1;
    storage <<= 8;
    storage |= ch2;
    storage <<= 8;
    storage |= ch3;
    storage <<= 8;
    storage |= ch4;

    const int byte_mask = 255;
    char res1 {static_cast<char>(storage & byte_mask)},
         res2 {static_cast<char>((storage >> 8) & byte_mask)},
         res3 {static_cast<char>((storage >> 16) & byte_mask)},
         res4 {static_cast<char>((storage >> 24) & byte_mask)};
    std::cout << "The 4 characters are stored in this int (hex): " << std::hex << storage << std::endl;
    std::cout << "The 4 bytes are: " 
              << res1 << " " << res2 << " " << res3 << " " << res4
              << std::endl;
}