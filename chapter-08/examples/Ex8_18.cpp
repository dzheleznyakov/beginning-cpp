// Using recursion to implement the quicksort algorithm
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

using std::string;
using PWord = std::shared_ptr<string>;
using PWords = std::vector<PWord>;

void swap(PWords &pwords, size_t first, size_t second);
void sort(PWords &pwords, size_t start, size_t end);
void extract_words(PWords &pwords, const string &text, const string &separators);
void show_words(const PWords &pwords);
size_t max_word_length(const PWords &pwords);

int main()
{
    PWords pwords;
    string text;
    const string separators{" ,.!?;:\"'\n-"};

    std::cout << "Enter a string terminated by *:" << std::endl;
    getline(std::cin, text, '*');

    extract_words(pwords, text, separators);
    if (pwords.size() == 0)
    {
        std::cout << "No words in text." << std::endl;
        return 0;
    }

    sort(pwords, 0, pwords.size() - 1);
    show_words(pwords);
}

void swap(PWords &pwords, size_t first, size_t second)
{
    PWord temp{pwords[first]};
    pwords[first] = pwords[second];
    pwords[second] = temp;
}

void sort(PWords &pwords, size_t start, size_t end)
{
    if (!(start < end))
        return;

    swap(pwords, start, (start + end) / 2);

    size_t current{start};
    for (size_t i{start + 1}; i <= end; ++i)
    {
        if (*(pwords[i]) < *(pwords[start]))
            swap(pwords, ++current, i);
    }

    swap(pwords, start, current);
    if (current > start)
        sort(pwords, start, current - 1);
    if (end > current + 1)
        sort(pwords, current + 1, end);
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
