// Using a stack defined by nested class templates
#include <iostream>
#include <string>
#include "Stack.h"

using std::string;

int main()
{
    const char *words[]{"The", "quick", "brown", "fox", "jumps"};
    Stack<const char *> wordStack;
    for (size_t i{}; i < sizeof(words) / sizeof(words[0]); ++i)
        wordStack.push(words[i]);

    Stack<const char *> newStack{wordStack};
    while (!newStack.isEmpty())
        std::cout << newStack.pop() << " ";
    std::cout << std::endl;

    while (!wordStack.isEmpty())
        newStack.push(wordStack.pop());

    while (!newStack.isEmpty())
        std::cout << newStack.pop() << " ";
    std::cout << std::endl;

    std::cout << std::endl
              << "Enter a line of text:" << std::endl;
    string text;
    std::getline(std::cin, text);

    Stack<const char> characters;
    for (size_t i{}; i < text.length(); ++i)
        characters.push(text[i]);

    std::cout << std::endl;
    while (!characters.isEmpty())
        std::cout << characters.pop();
    std::cout << std::endl;
}
