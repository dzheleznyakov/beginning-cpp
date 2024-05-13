/*
    Write a program that accepts two to four command line arguments.
    If it is called less than two, or more than four arguments,
    output a message telling the user what they should do, and then exit.
    If the number of arguments is correct, output them, each on a separate line.
*/
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 5)
    {
        std::cout << "The number of arguments this program accepts is from 2 to 4; you passed " << (argc - 1) << "."
                  << "\nPlease restart the program with the correct number of arguments." << std::endl;
        return 0;
    }

    std::cout << "The arguments passed into this program are:\n";
    for (int i{1}; i < argc; ++i)
        std::cout << *(argv + i) << std::endl;
}
