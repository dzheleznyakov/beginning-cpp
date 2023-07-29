// Using the bitwise operators
#include <iostream>
#include <iomanip>

using std::setw;

int main() 
{
    unsigned int red {0xFF0000u};
    unsigned int white {0xFFFFFFu};

    std::cout << std::hex
              << std::setfill('0');

    std::cout << "Try out bitwise AND and OR operators:";
    std::cout << "\nInitial value red = " << setw(8) << red;
    std::cout << "\nComplement   ~red = " << setw(8) << ~red;

    std::cout << "\nInitial value white = " << setw(8) << white;
    std::cout << "\nComplement   ~white = " << setw(8) << ~white;

    std::cout << "\nBitwise AND red & white = " << setw(8) << (red & white);
    std::cout << "\nBitwise  OR red | white = " << setw(8) << (red | white);

    std::cout << "\n\nNow try successive exclusive OR (XOR) operations: ";
    unsigned int mask {red ^ white};
    std::cout << "\nmask = red ^ white = " << setw(8) << mask;
    std::cout << "\n        mask ^ red = " << setw(8) << (mask ^ red);
    std::cout << "\n      mask ^ white = " << setw(8) << (mask ^ white);

    unsigned int flags {0xFF};
    unsigned int bit1mask {0x1};
    unsigned int bit6mask {0x20};
    unsigned int bit20mask {0x80000};

    std::cout << "\n\nUse mask to select or set a particular flag bit:";
    std::cout << "\nSelect bit 1 from flags   : " << setw(8) << (flags & bit1mask);
    std::cout << "\nSelect bit 6 from flags   : " << setw(8) << (flags & bit6mask);
    std::cout << "\nSwitch off bit 6 in flags : " << setw(8) << (flags &= ~bit6mask);
    std::cout << "\nSwitch on bit 30 in flags : " << setw(8) << (flags |= bit20mask);
    std::cout << std::endl;
}