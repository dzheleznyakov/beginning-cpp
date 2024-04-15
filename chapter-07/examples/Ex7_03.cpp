// Comparing strings
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <vector>

using std::string;

int main()
{
    std::vector<string> names;
    string input_name;
    char answer{};

    do
    {
        std::cout << "Enter a name: ";
        std::cin >> input_name;
        names.push_back(input_name);

        std::cout << "Do you want to enter another name? (y/n): ";
        std::cin >> answer;
    } while (tolower(answer) == 'y');

    // sort the names in ascending sequence
    string temp;
    bool sorted{false};
    while (!sorted)
    {
        sorted = true;
        for (size_t i{}; i < names.size(); ++i)
        {
            if (names[i - 1] > names[i])
            {
                temp = names[i];
                names[i] = names[i - 1];
                names[i - 1] = temp;
                sorted = false;
            }
        }
    }

    // find the length of the longest name
    size_t max_length{};
    for (auto &name : names)
    {
        if (max_length < name.length())
            max_length = name.length();
    }

    // output the sorted names 5 to a line
    std::cout << "In ascending sequence the names you entered are:\n";
    size_t field_width{max_length + 2};
    size_t count{};
    for (auto &name : names)
    {
        std::cout << std::setw(field_width) << name;
        if (!(++count % 5))
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
