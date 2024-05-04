// Using a reference parameter
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::string;
using std::vector;

void find_words(vector<string> &words, string &str, const string &separators);
void list_words(const vector<string> &words);

int main()
{
    string text;
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');

    const string separators{" ,;:.\"!?'\n-"};
    vector<string> words;

    find_words(words, text, separators);
    list_words(words);
}

void find_words(vector<string> &words, string &str, const string &separators)
{
    size_t start{str.find_first_not_of(separators)};
    size_t end{};

    while (start != string::npos)
    {
        end = str.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = str.length();

        words.push_back(str.substr(start, end - start));
        start = str.find_first_not_of(separators, end + 1);
    }
}

void list_words(const vector<string> &words)
{
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
