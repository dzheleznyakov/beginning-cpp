/*
    Create a program that uses a do-while loop to count the number
    of non-whitespace chracters entered on a line.
    The count should end when the first # character is found.
*/
#include <iostream>
#include <locale>

int main()
{
    int count{};
    const size_t max_size_line = 1000;
    char text[max_size_line]{};
    std::cout << "Enter a text ending with #: ";

    bool done{false};
    do
    {
        std::cin.getline(text, max_size_line);
        for (size_t i = 0; i < text[i] != '\0'; ++i)
        {
            char ch = text[i];
            if (ch == '#')
            {
                done = true;
                break;
            }
            if (!isspace(ch))
                ++count;
        }
    } while (!done);

    std::cout << "The number of non-whitespace characters is " << count << std::endl;
}