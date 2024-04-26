/*
    Write a program that reads a text string of arbitrary length
    from the keyboard followed by a string containing one or more
    letters. Output a list of all the whole words in the text
    that begin with any of the letters, upper or lower case.
*/
#include <iomanip>
#include <iostream>
#include <locale>
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

int main()
{
    string text;
    std::cout << "Enter your text:\n";
    std::getline(std::cin, text);

    string letters;
    std::cout << "Enter the letters the words you are interested in start: ";
    std::cin >> letters;

    if (!letters.length())
    {
        std::cout << "You did not enter any letters." << std::endl;
        return 0;
    }

    string lletters;
    char ch{};
    for (size_t i{}; i < letters.length(); ++i)
    {
        ch = letters[i];
        if (std::isalpha(ch))
            lletters += std::tolower(ch);
        else
            lletters += ch;
    }

    vector<shared_ptr<string>> words;
    const string separators{" ,.;:\"!?'\n-"};
    size_t start{text.find_first_not_of(separators)};
    size_t end{};
    string word;
    char first_char{};
    size_t max_length{};
    while (start != string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = text.length();
        auto pWord = std::make_shared<string>();
        *pWord = text.substr(start, end - start);
        first_char = std::tolower((*pWord)[0]);
        if (lletters.find(first_char) != string::npos)
        {
            words.push_back(pWord);
            if (max_length < pWord->length())
                max_length = pWord->length();
        }
        start = text.find_first_not_of(separators, end + 1);
    }

    const size_t perline(3);
    std::cout << "The list of the found words is:"
              << std::left;
    size_t count{};
    for (auto pWord : words)
    {
        if (count++ % perline == 0)
            std::cout << std::endl;
        std::cout << std::setw(max_length + 2)
                  << (*pWord);
    }
    std::cout << std::endl;
}
