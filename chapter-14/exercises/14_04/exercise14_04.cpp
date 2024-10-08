#include <iostream>
#include <memory>
#include <vector>

#include "Inches.h"
#include "Meters.h"
#include "Yards.h"
#include "Perches.h"

using std::vector;
template <typename T>
using ptr = std::shared_ptr<T>;
using Lengths = vector<ptr<BaseLength>>;

void readLengths(Lengths &lengths);
ptr<BaseLength> newLength(double value, char unitCode);
void printLengths(const Lengths &lengths);

int main()
{
    vector<ptr<BaseLength>> lengths{};
    readLengths(lengths);
    printLengths(lengths);
}

void readLengths(Lengths &lengths)
{
    char unitCode{};
    double value{};
    do
    {
        std::cout << "Enter the length (0 to stop): ";
        std::cin >> value;
        if (value == 0.0)
            break;
        std::cout << "Choose the length unit\n"
                  << "  (i) for inches, (m) for meters, (y) for yards, or (p) for perches or (s) to stop: ";
        std::cin >> unitCode;

        if (unitCode == 's')
            break;

        auto pLength = newLength(value, unitCode);
        if (pLength == nullptr)
        {
            std::cout << "The unit code \"" << unitCode << "\" is not recognised." << " Try again.\n\n"
                      << std::endl;
            continue;
        }
        lengths.push_back(pLength);
    } while (true);
}

ptr<BaseLength> newLength(double value, char unitCode)
{
    if (unitCode == 'i')
        return std::make_shared<Inches>(value);
    if (unitCode == 'm')
        return std::make_shared<Meters>(value);
    if (unitCode == 'y')
        return std::make_shared<Yards>(value);
    if (unitCode == 'p')
        return std::make_shared<Perches>(value);
    return nullptr;
}

void printLengths(const Lengths &lengths)
{
    for (auto p : lengths)
        std::cout << "\nThe length of " << p->getValueMm() << " mm  is"
                  << "\n  " << Inches{*p}
                  << "\n  " << Meters{*p}
                  << "\n  " << Yards{*p}
                  << "\n  " << Perches{*p};
    std::cout << std::endl;
}
