#include <iostream>
#include <locale>

int main() {
    char letter {};
    std::cout << "Enter a letter: ";
    std::cin >> letter;

    if (isalpha(letter)) {
        std::cout << "You entered:";
        switch (tolower(letter)) {
            case 'a': case 'o': case 'e': case 'i': case 'u':
                std::cout << "\n  - a vowel ";
                break;
            default:
                std::cout << "\n  - a consonant ";

        }
        if (isupper(letter)) {
            std::cout << "\n  - an upper case letter";
        } else {
            std::cout << "\n  - a lower case letter";
        }
    } else {
        std::cout << "You did not enter a letter.";
    }
    std::cout << std::endl;
}