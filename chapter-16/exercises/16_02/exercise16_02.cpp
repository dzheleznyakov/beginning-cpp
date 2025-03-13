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

    size_t max_length{getMaxLength(words) + 2};
    const size_t PER_LINE{5};

    std::cout << "\nWords in sequence:";
    auto fIterator{words.forward()};
    size_t word_in_line_count{};
    while (fIterator.hasNext())
    {
        if (word_in_line_count++ % PER_LINE == 0)
            std::cout << std::endl;
        std::cout << std::setw(max_length) << fIterator.next();
    }
    std::cout << std::endl;

    std::cout << "\nWords in reverse:";
    auto rIterator{words.reverse()};
    word_in_line_count = 0;
    while (rIterator.hasNext())
    {
        if (word_in_line_count++ % PER_LINE == 0)
            std::cout << std::endl;
        std::cout << std::setw(max_length) << rIterator.next();
    }
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
    auto iterator{words.forward()};
    while (iterator.hasNext())
    {
        string word{iterator.next()};
        if (word.length() > max_length)
            max_length = word.length();
    }
    return max_length;
}
