// Using static_assert() in a class template
#include <iostream>
#include <iomanip>
#include "Box.h"
#include "Array.h"

int main()
{
    const size_t nValues{50};
    Array<double> values{nValues};
    try
    {
        for (size_t i{}; i < nValues; ++i)
            values[i] = i + 1;

        std::cout << "Sums of pairs of elements:";
        size_t lines{};
        for (size_t i{nValues - 1}; i >= 0; --i)
            std::cout << (lines++ % 5 == 0 ? "\n" : "")
                      << std::setw(5) << values[i] + values[i - 1];
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "\nout_of_range exception object caught! " << e.what() << std::endl;
    }

    try
    {
        const size_t nBoxes{10};
        Array<Box> boxes{nBoxes};
        for (size_t i{}; i <= nBoxes; ++i)
            std::cout << "Box volume is " << boxes[i].volume() << std::endl;
    }
    catch (const std::out_of_range &ex)
    {
        std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
    }
}
