// Linked list template
#include <iostream>
#include <iomanip>
#include <string>

#include "LinkedList.h"

using std::string;
using Words = LinkedList<string>;

void extractWords(string text, Words &words);
size_t getMaxLength(const Words &words);

int main()
{
    string text;
    std::cout << "Enter some text terminating with *:" << std::endl;
    std::getline(std::cin, text, '*');

    Words words;
    extractWords(text, words);

    const size_t MAX_LENGTH{getMaxLength(words) + 2};
    const size_t PER_LINE{5};
    size_t word_in_line_count{};

    auto print = [PER_LINE, MAX_LENGTH, &word_in_line_count](const string &word)
    {
        if (word_in_line_count++ % PER_LINE == 0)
            std::cout << std::endl;
        std::cout << std::setw(MAX_LENGTH) << word;
    };

    std::cout << "\nWords in sequence:";
    words.forEach(print);

    word_in_line_count = 0;
    std::cout << "\nWords in reverse:";
    words.forEachReversed(print);

    std::cout << std::endl;
}

void extractWords(string text, Words &words)
{
    const string separators{" ,.;:\"!?'\n-"};
    size_t start{text.find_first_not_of(separators)};
    size_t end{};
    while (start != string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = text.length();
        words.add(text.substr(start, end - start));
        start = text.find_first_not_of(separators, end + 1);
    }
}

size_t getMaxLength(const Words &words)
{
    size_t max_length{};
    auto getMaxLength = [&](const string &word)
    {
        if (word.length() > max_length)
            max_length = word.length();
    };
    words.forEach(getMaxLength);
    return max_length;
}
