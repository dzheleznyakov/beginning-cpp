// Accessing characters in a string
#include <iostream>
#include <string>
#include <locale>

using std::string;

int main()
{
    string text;
    std::cout << "Enter a line of text:\n";
    std::getline(std::cin, text);

    int vowels{};
    int consonants{};
    for (size_t i{}; i < text.length(); ++i)
    {
        if (std::isalpha(text[i]))
        {
            switch (std::tolower(text[i]))
            {
            case 'a':
            case 'e':
            case 'o':
            case 'i':
            case 'u':
                ++vowels;
                break;
            default:
                ++consonants;
                break;
            }
        }
    }

    std::cout << "Your input contained " << vowels << " vowels and "
              << consonants << " consonants." << std::endl;
}
