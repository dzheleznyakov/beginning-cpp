// Using the conditional operator to select output
#include <iostream>

int main() 
{
    int mice {};
    int brown {};
    int white {};

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;
    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    mice = brown + white;
    std::cout << "You have " << mice
              << (mice == 1 ? " mouse " : " mice ")
              << "in total." << std::endl;
}