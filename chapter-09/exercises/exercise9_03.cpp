/*
    Define and test a lambda expression that return the number of elements
    in a vector<string> container that begin with a given letter.
*/
#include <iostream>
#include <locale>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;

using PWord = std::shared_ptr<string>;
using PWords = vector<PWord>;

void extractWords(PWords &pwords, const string &text, const string &separators);
int countWords(const PWords &pwords, const char letter);

int main()
{
    PWords words;
    string text;
    char letter{};
    const string separators{" ,.!?;:\"'\n-"};

    std::cout << "Enter the text ending with #:\n";
    getline(std::cin, text, '#');
    std::cout << "Enter the letter that the words you want to count start with: ";
    std::cin >> letter;

    extractWords(words, text, separators);
    int count{countWords(words, letter)};
    std::cout << "The number of words starting with '" << letter << "' is " << count << std::endl;
}

void extractWords(PWords &pwords, const string &text, const string &separators)
{
    size_t start{text.find_first_not_of(separators)};
    size_t end{};

    while (start != string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = text.length();
        PWord pword = std::make_shared<string>(text.substr(start, end - start));
        pwords.push_back(pword);
        start = text.find_first_not_of(separators, end + 1);
    }
}

int countWords(const PWords &pwords, const char letter)
{
    int count{};
    for (auto pword : pwords)
    {
        char first_letter{(*pword)[0]};
        if (std::tolower(first_letter) == letter)
            ++count;
    }
    return count;
}
