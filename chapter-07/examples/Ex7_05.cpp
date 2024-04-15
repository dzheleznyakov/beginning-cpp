// Searching a string for characters from a set
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::string;

int main()
{
    string text;
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');

    const string separators{" ,.;:\"!?'\n-"};
    std::vector<string> words;

    size_t start{text.find_first_not_of(separators)};
    size_t end{};

    while (start != string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = text.length();
        words.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(separators, end + 1);
    }

    std::cout << "Your string contains the following " << words.size() << " words:\n";
    size_t count{};
    for (const auto &word : words)
    {
        std::cout << std::setw(15) << word;
        if (!(++count % 5))
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
