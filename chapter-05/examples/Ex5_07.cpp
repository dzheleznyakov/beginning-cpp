// Using a do-while loop to manage input
#include <iostream>
#include <locale>

int main()
{
    char reply{};
    int count{};
    double temperature{};
    double average{};

    do
    {
        std::cout << "Enter a temperature reading: ";
        std::cin >> temperature;

        average += temperature;
        ++count;

        std::cout << "Do you want to enter another? (y/n): ";
        std::cin >> reply;
    } while (tolower(reply) == 'y');

    std::cout << "The average temperature is " << (average / count) << std::endl;
}