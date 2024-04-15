// Searching a string
#include <iostream>
#include <string>

using std::string;

int main()
{
    string text{};
    string word{};
    std::cout << "Enter the string to be searched and press Enter:\n";
    std::getline(std::cin, text);

    std::cout << "Enter the string to be found and press Enter:\n";
    std::getline(std::cin, word);

    size_t count{};
    size_t index{};
    while ((index = text.find(word, index)) != string::npos)
    {
        ++count;
        index += word.length();
    }
    std::cout << "Your text contained " << count << " occurrences of \""
              << word << "\"." << std::endl;
}
