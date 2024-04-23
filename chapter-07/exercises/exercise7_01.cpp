/*
    Write a program that reads and stores the first names of any number of students,
    along with their grades. Calculate and output the average grade, and output
    the names and grades of all the students in a table with the name
    and grade for three students on each line.
*/
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

int main()
{
    vector<shared_ptr<string>> names;
    vector<shared_ptr<int>> grades;

    do
    {
        std::cout << "Enter the name and the grade of the next student, or 'quit' to end: ";
        auto pName = std::make_shared<string>();
        auto pGrade = std::make_shared<int>();

        std::cin >> *pName;
        if (*pName == "quit")
            break;
        std::cin >> *pGrade;

        names.push_back(pName);
        grades.push_back(pGrade);
    } while (true);

    int total{};
    for (auto pGrage : grades)
        total += *pGrage;
    double avg{1.0 * total / grades.size()};
    std::cout << "\n\nThe average grade is " << avg << std::endl;

    int max_name_length{};
    for (auto pName : names)
    {
        if (pName->length() > max_name_length)
            max_name_length = pName->length();
    }
    const int perline{3};
    std::cout << std::left;
    for (size_t i{}; i < names.size(); ++i)
    {
        if (i % perline == 0)
            std::cout << std::endl;
        std::cout << std::setw(max_name_length + 1) << *names.at(i)
                  << std::setw(4) << *grades.at(i);
    }
    std::cout << std::endl;
}
