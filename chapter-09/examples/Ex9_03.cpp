// Sorting words in ascending or descending sequence
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <utility>

using std::string;
using PWord = std::shared_ptr<string>;
using PWords = std::vector<PWord>;

void mysort(PWords &data, size_t start, size_t end, std::function<bool(const PWord, const PWord)> compare);
void extract_words(PWords &pwords, const string &text, const string &separators);
void show_words(const PWords &pwords);
size_t max_word_length(const PWords &pwords);

int main()
{
    PWords pwords;
    string text;
    const string separators{" ,.!?\"'\n-"};

    std::cout << "Enter a string terminated by *:" << std::endl;
    getline(std::cin, text, '*');

    extract_words(pwords, text, separators);
    if (pwords.size() == 0)
    {
        std::cout << "No words in text." << std::endl;
        return 0;
    }

    size_t start{}, end{pwords.size() - 1};
    std::cout << "\nWords in ascending sequence:\n";
    mysort(pwords, start, end, [](const PWord p1, const PWord p2)
           { return *p1 < *p2; });
    show_words(pwords);

    std::cout << "\nWords in descending sequence:\n";
    mysort(pwords, start, end, [](const PWord p1, const PWord p2)
           { return *p1 > *p2; });
    show_words(pwords);
}

void mysort(PWords &data, size_t start, size_t end, std::function<bool(const PWord, const PWord)> compare)
{
    if (!(start < end))
    {
        return;
    }

    std::swap(data[start], data[(start + end) / 2]);

    size_t current{start};
    for (size_t i{start + 1}; i <= end; ++i)
    {
        if (compare(data[i], data[start]))
            std::swap(data[++current], data[i]);
    }

    std::swap(data[start], data[current]);

    if (current > start)
        mysort(data, start, current - 1, compare);
    if (end > current + 1)
        mysort(data, current + 1, end, compare);
}

void extract_words(PWords &pwords, const string &text, const string &separators)
{
    size_t start{text.find_first_not_of(separators)};
    size_t end{};

    while (start != string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = text.length();
        pwords.push_back(std::make_shared<string>(text.substr(start, end - start)));
        start = text.find_first_not_of(separators, end + 1);
    }
}

void show_words(const PWords &pwords)
{
    const size_t field_width{max_word_length(pwords) + 2};
    const size_t words_per_line{8};
    std::cout << std::left << std::setw(field_width) << *pwords[0];

    size_t words_in_line{};
    for (size_t i{1}; i < pwords.size(); ++i)
    {
        if ((*pwords[i])[0] != (*pwords[i - 1])[0] || ++words_in_line == words_per_line)
        {
            words_in_line = 0;
            std::cout << std::endl;
        }
        std::cout << std::setw(field_width) << *pwords[i];
    }
    std::cout << std::endl;
}

size_t max_word_length(const PWords &pwords)
{
    size_t max{};
    for (auto &pword : pwords)
        if (max < pword->length())
            max = pword->length();
    return max;
}
