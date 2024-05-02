// Using a reference parameter - refactored
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;

std::shared_ptr<vector<string>> find_words(const string &str, const string &separators);
void list_words(const std::shared_ptr<vector<string>> pWords);

int main()
{
    string text;
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');

    const string separators{" ,;:.\"!?'\n-"};
    vector<string> words;

    list_words(find_words(text, separators));
}

std::shared_ptr<vecotr<string>> find_words(const string &str, const string &separators)
{
    auto pWords = std::make_shared<vector<string>>();
    size_t start{str.find_first_not_of(separators)};
    size_t end{};

    while (start != string::npos)
    {
        end = str.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = str.length();

        pWords->push_back(str.substr(start, end - start));
        start = str.find_first_not_of(separators, end + 1);
    }
    return pWords;
}

void list_words(const std::shared_ptr<vector<string>> pWords)
{
    std::cout << "Your string contains the following " << pWords->size() << " words:\n";
    size_t count{};
    for (const auto &word : pWords)
    {
        std::cout << std::setw(15) << word;
        if (!(++count % 5))
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
