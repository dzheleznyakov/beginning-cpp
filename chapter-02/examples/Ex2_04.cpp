// Sizing a pond for happy fish
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::sqrt;

int main() 
{
    const double fish_factor {2.0 / 0.5};
    const unsigned int inches_per_foot {12};
    const double pi {3.14159265};

    unsigned int fish_count {};
    double fish_length {};

    cout << "Enter the number of fish you want to keep: ";
    cin >> fish_count;
    cout << "Enter the average fish length in inches: ";
    cin >> fish_length;
    fish_length /= inches_per_foot;

    double pond_area {fish_count * fish_length * fish_factor};
    double pond_diameter {2.0 * sqrt(pond_area / pi)};

    cout << "\nPond diamer required for " << fish_count << " fish is "
         << std::fixed << std::setprecision(2)
         << pond_diameter << " feet." << std::endl;
}