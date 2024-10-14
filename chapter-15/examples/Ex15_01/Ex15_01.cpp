// Throwing and catching exceptions
#include <iostream>

int main()
{
    for (size_t i{}; i < 7; ++i)
    {
        try
        {
            if (i < 3)
                throw i;
            std::cout << " i not thrown - value is " << i << std::endl;

            if (i > 5)
                throw "Here is another!";

            std::cout << "Ent of the try block." << std::endl;
        }
        catch (size_t i)
        {
            std::cout << " i caught - value is " << i << std::endl;
        }
        catch (const char *message)
        {
            std::cout << "\"" << message << "\" caught" << std::endl;
        }
        std::cout << "End of the for loop body (after the catch blocks) - i is " << i << std::endl;
    }
}
