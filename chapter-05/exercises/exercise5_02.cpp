/*
    Write a program that uses a while loop to accumulate
    the sum of an arbitrary number of integers that are entered by the user.
    The program should output the total of all the values
    and the overal average as a floating-point value.
*/
#include <iostream>

int main()
{
    int total{0};
    int num{};
    int count{0};
    do
    {
        std::cout << "Enter an integer (0 to finish): ";
        std::cin >> num;
        if (num == 0)
            break;
        ++count;
        total += num;
    } while (true);

    if (count == 0)
        count = 1;

    double average{static_cast<double>(total) / static_cast<double>(count)};

    std::cout << "\n\nThe total sum of the entered integers is " << total
              << "\nThe average of the entered integers is " << average << std::endl;
}