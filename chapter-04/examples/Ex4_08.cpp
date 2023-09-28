// Multiple case actions.
#include <iostream>
#include <locale>

int main()
{
    char letter {};
    std::cout << "Enter a letter: ";
    std::cin >> letter;

    if (isalpha(letter)) {
        switch (tolower(letter)) 
        {
            case 'a': case 'o': case 'e': case 'i': case 'u':
                std::cout << "You entered a vowel." << std::endl;
                break;
            default:
                std::cout << "You enetered a consonant." << std::endl;
                break;
        }
    }
    else
    {
        std::cout << "You did not enter a letter." << std::endl;
    }
}