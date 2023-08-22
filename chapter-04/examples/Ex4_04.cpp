// Using the if-else
#include <iostream>

int main()
{
    long number {};
    std::cout << "Enter an integer less than 2 billion: ";
    std::cin >> number;

    if (number % 2L) 
    {
        std::cout << "Your number is odd." << std::endl;
    }
    else 
    {
        std::cout << "Your number is even." << std::endl;
    }
}