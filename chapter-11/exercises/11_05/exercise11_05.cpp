/*
    Modify the Package class in Example 11-08 so that it contains
    a smart pointer to the previous object in the list. Modify the Package
    and Truckload classes to make use of this, including providing the
    ability to iterate though Box objects in the list in reverse order and to
    list the objexts in a Truckload object in reverse sequence. Devise a
    main() program to demonstrate the new capabilities.
*/
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Box.h"
#include "Truckload.h"

inline size_t random(size_t count)
{
    return 1 + static_cast<size_t>(count * static_cast<double>(std::rand()) / (RAND_MAX + 1.0));
}

int main()
{
    const size_t dimLimit{99};
    std::srand((unsigned)std::time(0));

    Truckload load1;

    const size_t boxCount{12};
    for (size_t i{}; i < boxCount; ++i)
        load1.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

    std::cout << "The first list:\n";
    load1.listBoxes();
    std::cout << "\nThe first list in reversed order:\n";
    load1.listBoxesReversed();

    // Find the largest box in the list
    ptr<Box> pBox{load1.getFirstBox()};
    ptr<Box> pCurrentBox{load1.getNextBox()};
    while (pCurrentBox)
    {
        if (pBox->compare(*pCurrentBox) < 0)
            pBox = pCurrentBox;
        pCurrentBox = load1.getNextBox();
    }

    std::cout << "\nThe largest box in the first list is:";
    pBox->listBox();
    std::cout << std::endl;
    load1.deleteBox(pBox);
    std::cout << "\nAfter deleting the largest box, the list contains:\n";
    load1.listBoxes();
    std::cout << "\nAfter deleting the laragest box, the list contains (in reversed order):\n";
    load1.listBoxesReversed();

    const size_t nBoxes{20};
    std::vector<ptr<Box>> boxes;

    for (size_t i{}; i < nBoxes; ++i)
        boxes.push_back(std::make_shared<Box>(
            random(dimLimit), random(dimLimit), random(dimLimit)));

    Truckload load2{boxes};
    std::cout << "\nThe second list:\n";
    load2.listBoxes();
    std::cout << "\nThe second list in reversed order:\n";
    load2.listBoxesReversed();

    pBox = load2.getFirstBox();
    pCurrentBox = load2.getNextBox();
    while (pCurrentBox)
    {
        if (pBox->compare(*pCurrentBox) > 0)
            pBox = pCurrentBox;
        pCurrentBox = load2.getNextBox();
    }

    std::cout << "\nThe smallest box in the second list is";
    pBox->listBox();
    std::cout << std::endl;

    pBox = load2.getLastBox();
    pCurrentBox = load2.getPrevBox();
    while (pCurrentBox)
    {
        if (pBox->compare(*pCurrentBox) > 0)
            pBox = pCurrentBox;
        pCurrentBox = load2.getPrevBox();
    }

    std::cout << "\nDouble checking that the smallest box in the second list is";
    pBox->listBox();
    std::cout << std::endl;
}
