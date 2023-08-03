#include <iostream>

int main() {
    unsigned int k {430U};
    unsigned int j {(k >> 4) & ~(~0 << 3)};
    std::cout << j << std::endl;
}