// Demonstrating scope, lefitime and global variables
#include <iostream>

long count1 {999L};
double count2 {3.14};
int count3;

int main()
{ // Function scope starts here
    int count1 {10};
    int count3 {50};
    std::cout << "Value of outer count1 = " << count1 << std::endl;
    std::cout << "Value of global count1 = " << ::count1 << std::endl;
    std::cout << "Value of global count2 = " << count2 << std::endl;

    { // New block scope starts here
        int count1 {20};
        int count2 {30};
        std::cout << "\nValue of inner count1 = " << count1 << std::endl;
        std::cout << "Value of global count1 = " << ::count1 << std::endl;
        std::cout << "Value of inner count2 = " << count2 << std::endl;
        std::cout << "Value of global count2 = " << ::count2 << std::endl;

        count1 = ::count1 + 3;
        ++::count1;
        std::cout << "\nValue of inner count1 = " << count1 << std::endl;
        std::cout << "Value of global count1 = " << ::count1 << std::endl;

        count3 += count2;
    } // The bloks scope ends here

    std::cout << "\nValue of outer count1 = " << count1 << std:: endl
              << "Value of outer count3 = " << count3 << std::endl;
    std::cout << "Value of global count3 = " << ::count3 << std::endl;
    std::cout << "Value of global count2 = " << ::count2 << std::endl;
} // Functioin scope ends here