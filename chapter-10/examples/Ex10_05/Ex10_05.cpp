// Using a static assertion
#include <vector>
#include <iostream>
#include <string>
#include "average.h"

int main()
{
    std::vector<double> data{1.5, 2.5, 3.5, 4.5};
    std::cout << "The average value of data values is " << average(data) << std::endl;

    // Uncomment the next two lines for a compile error
    // std::vector<std::string> words{"this", "that", "them", "those"};
    // std::cout << "The average value of word values is " << average(words) << std::endl;
}
