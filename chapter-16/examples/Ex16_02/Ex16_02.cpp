// Using a class template with a non-type parameter
#include <iostream>
#include <iomanip>
#include "Array.h"
#include "Box.h"

int main()
{
    try
    {
        try
        {
            const size_t size{21};
            const int start{-10};
            const int end{start + static_cast<int>(size) - 1};

            Array<double, start> values{size};

            for (int i{start}; i <= end; ++i)
                values[i] = i - start + 1;

            std::cout << "Sums of paris of elements: ";
            size_t lines{};
            for (int i{end}; i >= start; --i)
                std::cout << (lines++ % 5 == 0 ? "\n" : "")
                          << std::setw(5) << values[i] + values[i - 1];
        }
        catch (const std::out_of_range &ex)
        {
            std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
        }

        const int start{};
        const size_t size{11};

        Array<Box, start - 5> boxes{size};

        for (int i{start - 5}; i <= start + static_cast<int>(size) - 5; ++i)
            std::cout << "Box[" << i << "] volume is " << boxes[i].volume() << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cerr << "\n" << typeid(ex).name() << " exception caught in main()! "
                  << ex.what() << std::endl;
    }
}
