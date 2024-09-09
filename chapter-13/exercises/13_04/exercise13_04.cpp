#include <iostream>
#include <vector>

#include "Executive.h"

using std::vector;

int main()
{
    vector<Employee> employees{
        Employee{"John Smith", 35, "male", 745745},
        Employee{"Mary Brown", 38, "female", 395846},
        Employee{"Walter White", 50, "male", 290068},
        Employee{"Jesse Pinkman", 27, "male", 398549},
        Employee{"Jane Morgoulis", 26, "female", 390435}};

    vector<Executive> executives{
        Executive{"William Turner", 45, "male", 394399},
        Executive{"Barbara Kunalesku", 39, "female", 438699},
        Executive{"Jack Jonhson", 52, "male", 408086},
        Executive{"John Jackson", 52, "male", 408087},
        Executive{"Jojo Kondo", 33, "bifocal goat", 489845}};

    std::cout << "Displaying info about regular employees:\n";
    for (auto &emp : employees)
        std::cout << emp.who() << "\n";

    std::cout << "\nDisplaying info about executives:\n";
    for (auto &exec : executives)
        std::cout << exec.who() << "\n";

    std::cout << "\nDisplaying additional info about executives:\n";
    for (auto &emp : executives)
        std::cout << emp.Employee::who() << "\n";

    std::cout << std::endl;
}
