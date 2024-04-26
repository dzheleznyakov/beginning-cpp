/*
    Write a program that prompts for input of two words
    and determines whether one is an anagram of the other.
*/
#include <iostream>
#include <string>

using std::string;

int main()
{
    string word1;
    string word2;
    std::cout << "Enter two words: ";
    std::cin >> word1 >> word2;

    if (word1.length() != word2.length())
    {
        std::cout << "The words \"" << word1 << "\" and \"" << word2
                  << "\" are not anagrams of each other." << std::endl;
        return 0;
    }

    char *pword1{new char[word1.length()]};
    for (size_t i{}; i < word1.length(); ++i)
        *(pword1 + i) = word1[i];
    char *pword2{new char[word2.length()]};
    for (size_t i{}; i < word2.length(); ++i)
        *(pword2 + i) = word2[i];

    char temp{};
    bool sorted{false};
    while (!sorted)
    {
        sorted = true;
        for (size_t i{}; i < word1.length(); ++i)
        {
            if (*(pword1 + i - 1) > *(pword1 + i))
            {
                temp = *(pword1 + i);
                *(pword1 + i) = *(pword1 + i - 1);
                *(pword1 + i - 1) = temp;
                sorted = false;
            }
        }
    }
    sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (size_t i{}; i < word2.length(); ++i)
        {
            if (*(pword2 + i - 1) > *(pword2 + i))
            {
                temp = *(pword2 + i);
                *(pword2 + i) = *(pword2 + i - 1);
                *(pword2 + i - 1) = temp;
                sorted = false;
            }
        }
    }

    bool are_anagrams{true};
    for (size_t i{}; i < word1.length(); ++i)
    {
        if (*(pword1 + i) != *(pword2 + i))
        {
            are_anagrams = false;
            break;
        }
    }

    std::cout << "The words \"" << word1 << "\" and \"" << word2
              << "\" are" << (are_anagrams ? "" : " not") << " anagrams of each other." << std::endl;

    delete[] pword1;
    delete[] pword2;
}
