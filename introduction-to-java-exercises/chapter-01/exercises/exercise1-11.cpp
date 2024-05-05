/*
    The U.S. Census Bureau projects population based on the followin assumptions:
    - One birth every 7 seconds.
    - One death every 13 seconds.
    - One new immigrant every 45 seconds.
    Write a program to display the population for each of the next five years.
    Assume that the current population is 312,032,486, and one year has 365 days.
*/
#include <iostream>
#include <iomanip>

int main()
{
    const int DAYS_IN_YEAR{365};
    const int SECONDS_IN_DAY{24 * 60 * 60};
    const int SECONDS_IN_YEAR{DAYS_IN_YEAR * SECONDS_IN_DAY};

    const int SECONDS_PER_BIRTH{7};
    const int SECONDS_PER_DEATH{13};
    const int SECONDS_PER_IMMIGRANT{45};

    int population{312032486};
    std::cout << "The projected U.S. population is:\n";
    std::cout << "\nYear     Projected Population";
    std::cout << "\n----------------------------------";
    std::cout << "\nYear 0   " << population;

    population = population + SECONDS_IN_YEAR / SECONDS_PER_BIRTH - SECONDS_IN_YEAR / SECONDS_PER_DEATH + SECONDS_IN_YEAR / SECONDS_PER_IMMIGRANT;
    std::cout << "\nYear 1   " << population;

    population = population + SECONDS_IN_YEAR / SECONDS_PER_BIRTH - SECONDS_IN_YEAR / SECONDS_PER_DEATH + SECONDS_IN_YEAR / SECONDS_PER_IMMIGRANT;
    std::cout << "\nYear 2   " << population;

    population = population + SECONDS_IN_YEAR / SECONDS_PER_BIRTH - SECONDS_IN_YEAR / SECONDS_PER_DEATH + SECONDS_IN_YEAR / SECONDS_PER_IMMIGRANT;
    std::cout << "\nYear 3   " << population;

    population = population + SECONDS_IN_YEAR / SECONDS_PER_BIRTH - SECONDS_IN_YEAR / SECONDS_PER_DEATH + SECONDS_IN_YEAR / SECONDS_PER_IMMIGRANT;
    std::cout << "\nYear 4   " << population;

    population = population + SECONDS_IN_YEAR / SECONDS_PER_BIRTH - SECONDS_IN_YEAR / SECONDS_PER_DEATH + SECONDS_IN_YEAR / SECONDS_PER_IMMIGRANT;
    std::cout << "\nYear 5   " << population;

    std::cout << std::endl;
}
