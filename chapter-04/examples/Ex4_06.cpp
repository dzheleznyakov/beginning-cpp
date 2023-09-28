// Combining logical operators for loan approval
#include <iostream>

int main()
{
    int age {};
    int income {};
    int balance {};

    std::cout << "Please enter your age in years: ";
    std::cin >> age;
    std::cout << "Please enter your annual income in dollars: ";
    std::cin >> income;
    std::cout << "What is your current account balance in dollars: ";
    std::cin >> balance;

    if (age >= 21 && (income > 25000 || balance > 100000))
    {
        int loan {};
        if (2 * income < balance / 2) 
        {
            loan = 2 * income;
        }
        else
        {
            loan = balance / 2;
        }
        std::cout << "You can borrow up to $" << loan << "." << std::endl;
    }
    else
    {
        std::cout << "Unfortunately, you don't qualify for loan." << std::endl;
    }
}