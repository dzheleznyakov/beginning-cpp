/*
    Write a program that reads text entered over an arbitrary number of lines.
    Find and record each unique word that appears in the text
    and record the number of occurrences of each word. Output the words
    and the number of occurrences of each word, three words and
    their counts per line. Words and counts should align in columns.
*/
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

using std::string;

int main()
{
    string text;
    std::cout << "Enter some text terminating with *:\n";
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

    if (words.size() == 0)
    {
        std::cout << "No words were entered." << std::endl;
        return 0;
    }

    string temp;
    bool sorted{false};
    while (!sorted)
    {
        sorted = true;
        for (size_t i{}; i < words.size(); ++i)
        {
            if (words[i - 1] > words[i])
            {
                temp = words[i];
                words[i] = words[i - 1];
                words[i - 1] = temp;
                sorted = false;
            }
        }
    }

    size_t max_length{};
    for (auto &word : words)
    {
        if (max_length < word.length())
            max_length = word.length();
    }

    const int perline{3};
    string current{words[0]};
    string word;
    int count{1};
    int column_count{0};
    std::cout << std::left;
    for (size_t i{1}; i < words.size(); ++i)
    {
        word = words[i];
        if (current != word)
        {
            if (column_count++ % perline == 0)
            {
                std::cout << std::endl;
            }
            std::cout << std::setw(max_length + 1) << current
                      << std::setw(3) << count;
            current = word;
            count = 1;
        }
        else
        {
            ++count;
        }
    }
    if (column_count % perline == 0)
    {
        std::cout << std::endl;
    }
    std::cout << std::setw(max_length + 1) << current
              << std::setw(3) << count << std::endl;
}
