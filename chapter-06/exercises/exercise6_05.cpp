/*
    Write a program that will read an arbitrary number of age vaoues
    in years for students in each or an arbitrary number of classes.
    The number of ages is not known in advance but there can be
    up to 50 students in a class. Store the students age values
    for each class in a vector<T> container that you crete in the free store.
    A shared_ptr<T> for each vector<T> should be store in a vector<T>
    that is also created in the free store. After input is complete,
    list the ages of students in each class, 5 to a line,
    followed by the average age of the class.
*/
#include <iomanip>
#include <iostream>
#include <locale>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

int main()
{
    vector<shared_ptr<vector<int>>> classes;
    int age{};
    char answer{};
    char cls_name{'A'};

    while (true)
    {
        auto pCls = std::make_shared<vector<int>>();
        classes.push_back(pCls);
        int class_counter = 0;
        std::cout << "Enter the students' ages for the Class " << cls_name
                  << " separated by spaces. Maximum 50 students. Enter 1000 to end:\n";

        while (true)
        {
            std::cin >> age;
            if (age == 1000)
                break;
            pCls->push_back(age);
            if (++class_counter == 50)
            {
                while ((getchar()) != '\n')
                    ;
                break;
            }
        }

        if (cls_name == 'Z')
            break;
        std::cout << "Enter ages for the Class "
                  << ++cls_name << "? (y/n): ";
        std::cin >> answer;
        if (toupper(answer) == 'N')
            break;
    }

    cls_name = 'A';
    size_t line_count{};
    const size_t perline{5};
    int total{};
    size_t count{};
    std::cout << "\n\nHere is the classes age stats:\n";
    for (auto cls : classes)
    {
        std::cout << "\nThe ages for the Class " << cls_name << " are:";
        for (auto age : *cls)
        {
            total += age;
            if (count % perline == 0)
            {
                std::cout << std::endl;
                count = 0;
            }
            std::cout << std::setw(6) << age;
            ++count;
        }
        std::cout << "\nAverage age of the Class "
                  << cls_name++ << " is " << ((1.0 * total) / count) << std::endl;
        total = 0;
        count = 0;
    }
}
