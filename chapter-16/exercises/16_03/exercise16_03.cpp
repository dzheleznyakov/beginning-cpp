// Linked list and Sparse array
#include <iostream>
#include <locale>
#include <string>

#include "LinkedList.h"
#include "SparseArray.h"

using std::string;
using Words = LinkedList<string>;
using WordsPerLetter = SparseArray<Words>;

void extractWords(const string &text, WordsPerLetter &wordsPerLetter);
void processWord(const string &word, WordsPerLetter &wordsPerLetter);
string tolower(const string &str);
void printWords(const WordsPerLetter &wordsPerLetter);

int main()
{
    string text;
    std::cout << "Enter some text terminating with *:" << std::endl;
    std::getline(std::cin, text, '*');

    WordsPerLetter wordsPerLetter;
    extractWords(text, wordsPerLetter);

    std::cout << "\n\nThe words in the text are:\n\n"
              << std::endl;
    printWords(wordsPerLetter);
    std::cout << std::endl;
}

void extractWords(const string &text, WordsPerLetter &wordsPerLetter)
{
    const string separators{" ,.;:\"!?'\n-"};
    size_t start{text.find_first_not_of(separators)};
    size_t end{};
    while (start != string::npos)
    {
        end = text.find_first_of(separators, start + 1);
        if (end == string::npos)
            end = text.length();
        string word{text.substr(start, end - start)};
        processWord(word, wordsPerLetter);
        start = text.find_first_not_of(separators, end + 1);
    }
}

void processWord(const string &word, WordsPerLetter &wordsPerLetter)
{
    string lword{tolower(word)};
    size_t index = static_cast<size_t>(lword[0] - 'a');
    wordsPerLetter[index].add(lword);
}

string tolower(const string &str)
{
    string result;
    for (size_t i{}; i < str.length(); ++i)
        result += tolower(str[i]);
    return result;
}

void printWords(const WordsPerLetter &wordsPerLetter)
{
    auto printWord = [](const string &word)
    {
        std::cout << word << "  ";
    };
    auto printLine = [&printWord](const size_t index, const Words &words)
    {
        std::cout << static_cast<char>(index + 'a') << ": ";
        words.forEach(printWord);
        std::cout << "\n\n";
    };
    wordsPerLetter.forEach(printLine);
}
