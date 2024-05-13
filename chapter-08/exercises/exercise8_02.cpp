/*
    Write a function that reads a string or array of characters as input
    and reverses it. Justify your choice of parameter type?
    Provide a main() function to test your function that prompts for a string
    of characters, reverses them, and outputs the reversed string.
*/
#include <iostream>
#include <string>

using std::string;

void read_input(string &input);
void reverse(string &input);
void swap(string &input, size_t i, size_t j);
void output_result(const string &input);

int main()
{
    string input{};
    read_input(input);
    reverse(input);
    output_result(input);
}

void read_input(string &input)
{
    std::cout << "Enter a line of text:\n";
    std::getline(std::cin, input);
}

void reverse(string &input)
{
    size_t i{};
    size_t j{input.length() - 1};
    while (i < j)
        swap(input, i++, j--);
}

void swap(string &input, size_t i, size_t j)
{
    char temp{input[i]};
    input[i] = input[j];
    input[j] = temp;
}

void output_result(const string &input)
{
    std::cout << "\nThe reversed string is:\n"
              << input << std::endl;
}
