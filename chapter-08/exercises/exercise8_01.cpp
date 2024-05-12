/*
    Write a function, validate_input(), that accepts two integer arguments
    that represent the upper and lower limits for an integer that is to be
    entered. It should accept a third argument that is a string
    describing the input, the string being used in the prompt for input
    to be entered. The function should prompt for input of the value
    within the range specified by the first two arguments and include
    the string identifying the type of value to be entered. The function
    should check the input and continue to prompt for input until the value
    entered by the user is valid. Use the validate_input() function in a program
    that obtains a user's date of birth and outputs it in the form of this example:
    May 12, 2024.
    The program should be implemented so that separate functions,
    month(), year() and day() manage the input of the corresponding numerical values.
    Don't forget leap years - February 29, 2013 is not allowed!
*/
#include <iostream>
#include <string>

using std::string;

int get_year();
int get_month();
int get_day(int month, int year);
int validate_input(int lower, int upper, const string &prompt);
void print_date_of_birth(int year, int month, int day);
const string format_month(int month);

int main()
{
    int year{get_year()};
    int month{get_month()};
    int day{get_day(month, year)};
    std::cout << std::endl;
    print_date_of_birth(year, month, day);
    std::cout << std::endl;
}

int get_year()
{
    return validate_input(1900, 2020, "Please, enter the year when you were born");
}

int get_month()
{
    return validate_input(1, 12, "Please enter the month you were born in");
}

int get_day(int month, int year)
{
    int upper_limit{};
    bool is_leap_year{year % 4 == 0};
    switch (month)
    {
    case 2:
        upper_limit = is_leap_year ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        upper_limit = 30;
        break;
    default:
        upper_limit = 31;
        break;
    }
    return validate_input(1, upper_limit, "Please, enter the day when you were born");
}

int validate_input(int lower, int upper, const string &prompt)
{
    int value{};
    bool value_is_in_range{false};
    do
    {
        std::cout << prompt << " (from " << lower << " to " << upper << "): ";
        std::cin >> value;
        if (value >= lower && value <= upper)
            value_is_in_range = true;
    } while (!value_is_in_range);
    return value;
}

void print_date_of_birth(int year, int month, int day)
{
    std::cout << "Your date of birth is "
              << format_month(month) << " " << day
              << ", " << year << ".";
}

const string format_month(int month)
{
    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    default:
        return "December";
    }
}
