// Catching exceptions with a base class handler
#include <iostream>
#include "MyTroubles.h"

int main()
{
    Trouble trouble;
    MoreTrouble moreTrouble;
    BigTrouble bigTrouble;

    for (int i{}; i < 7; ++i)
    {
        try
        {
            if (i == 3)
                throw trouble;
            else if (i == 5)
                throw moreTrouble;
            else if (i == 6)
                throw bigTrouble;
        }
        catch (const Trouble &t)
        {
            std::cout << "Trouble object caught: " << t.what() << std::endl;
        }
        std::cout << "End of the for-loop (after the catch blocks) - i is " << i << std::endl;
    }

    std::cout << "\n\n"
              << std::endl;
    for (int i{}; i < 7; ++i)
    {
        try
        {
            if (i == 3)
                throw trouble;
            else if (i == 5)
                throw moreTrouble;
            else if (i == 6)
                throw bigTrouble;
        }
        catch (const Trouble &t)
        {
            std::cout << typeid(t).name() << " object caught: " << t.what() << std::endl;
        }
        std::cout << "End of the for-loop (after the catch blocks) - i is " << i << std::endl;
    }

    std::cout << "\n\n"
              << std::endl;
    for (int i{}; i < 7; ++i)
    {
        try
        {
            if (i == 3)
                throw trouble;
            else if (i == 5)
                throw moreTrouble;
            else if (i == 6)
                throw bigTrouble;
        }
        catch (const Trouble t)
        {
            std::cout << typeid(t).name() << " object caught: " << t.what() << std::endl;
        }
        std::cout << "End of the for-loop (after the catch blocks) - i is " << i << std::endl;
    }
}
