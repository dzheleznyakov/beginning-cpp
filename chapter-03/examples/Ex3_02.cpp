// Operations with enumerations
#include <iostream>
#include <iomanip>

using std::setw;

int main() 
{
    enum class Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    Day yesterday {Day::Monday}, today {Day::Tuesday}, tomorrow {Day::Wednesday}, poets_day {Day::Friday};

    enum class Punctuation : char {Comma = ',', Exclamation = '!', Questions = '?'};
    Punctuation ch = Punctuation::Comma;

    std::cout << "yesterday's value is " << static_cast<int>(yesterday)
              << static_cast<char>(ch) << " but poet's day is " << static_cast<int>(poets_day)
              << static_cast<char>(Punctuation::Exclamation) << std::endl;

    today = Day::Thursday;
    ch = Punctuation::Questions;
    tomorrow = {poets_day};

    std::cout << "Is today's value(" << static_cast<int>(today)
              << ") the same as poet's day(" << static_cast<int>(poets_day)
              << ")" << static_cast<char>(ch) << std::endl;
}