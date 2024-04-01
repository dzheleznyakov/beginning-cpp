// Using an array of pointers
#include <iostream>

int main()
{
    const char *pstars[]{
        "Fatty Arbuckle", "Clara Bow",
        "Lassie", "Slim Pickens",
        "Boris Karloff", "Mae West",
        "Oliver Hardy", "Greta Garbo"};
    size_t choice{};

    std::cout << "Pick a lucky star! Enter a number between 1 and "
              << sizeof(pstars) / sizeof(pstars[0]) << ": ";
    std::cin >> choice;

    if (choice >= 1 && choice <= sizeof(pstars) / sizeof(pstars[0]))
    {
        std::cout << "You lucky star is " << pstars[choice - 1] << std::endl;
    }
    else
    {
        std::cout << "Sorry, you haven't got your lucky star." << std::endl;
    }
}
