/*
    Write a program that reads a text string of an arbitrary length
    from the keyboard and prompts for entry of a word
    that is to be found in the string. The program should find
    and replace all occurrences of this word, regardless of case,
    by as many asterisks as there are characters in the word.
    It should then output the new string. Only whole words are to be replaced.
*/
#include <iostream>
#include <locale>
#include <string>

using std::string;

int main()
{
    string text;
    std::cout << "Enter your text:\n";
    std::getline(std::cin, text);

    string word;
    std::cout << "Enter the word to censor: ";
    std::cin >> word;

    string ltext;
    char ch{};
    for (size_t i{}; i < text.length(); ++i)
    {
        ch = text[i];
        if (std::isalpha(ch))
            ltext += std::tolower(ch);
        else
            ltext += ch;
    }
    string lword;
    for (size_t i{}; i < word.length(); ++i)
    {
        ch = word[i];
        if (std::isalpha(ch))
            lword += std::tolower(ch);
        else
            lword += ch;
    }

    const string separators{" ,.;:\"!?'\n-"};
    size_t pos{ltext.find(lword)};
    size_t length{lword.length()};
    while (pos != string::npos)
    {
        bool clear_on_left{
            pos == 0 ||
            separators.find(ltext[pos - 1]) != string::npos};
        bool clear_on_right{
            pos + length == ltext.length() ||
            separators.find(ltext[pos + length]) != string::npos};
        if (clear_on_left && clear_on_right)
            text = text.replace(pos, length, length, '*');
        pos = ltext.find(lword, pos + 1);
    }

    std::cout << "The cencored text is:\n"
              << text << std::endl;
}
