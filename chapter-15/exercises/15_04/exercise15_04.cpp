#include <iostream>
#include "SparseArray.h"

void printStatus(const SparseArray &sArr)
{
    std::cout << "\nSize is " << sArr.size() << std::endl;
    std::cout << sArr << std::endl;
}

void printStatus(const SparseArray &sArr, size_t index)
{
    std::cout << "\nValue at index " << index << " is " << sArr[index] << std::endl;
}

int main()
{
    SparseArray sArr{100};
    sArr.add(0.0);
    sArr.add(1.0);
    sArr.add(0.0);
    sArr.add(2.0);
    printStatus(sArr);

    sArr.add(1, 3.0);
    printStatus(sArr);

    sArr.add(3, 4.0);
    printStatus(sArr);

    sArr.add(5, 5.0);
    printStatus(sArr);

    sArr.add(10, 6.0);
    printStatus(sArr);

    sArr.add(0, 7.0);
    printStatus(sArr);

    sArr.remove(9);
    printStatus(sArr);

    sArr.remove(3);
    printStatus(sArr);

    sArr.remove(0);
    printStatus(sArr);

    sArr.remove(8);
    printStatus(sArr);

    sArr.add(3, 0.0);
    printStatus(sArr);

    sArr.set(5, 9.0);
    printStatus(sArr);

    sArr.set(5, 0.0);
    printStatus(sArr);

    sArr.add(0, 7.0);
    printStatus(sArr);

    sArr.set(0, 0.0);
    printStatus(sArr);

    sArr.set(5, 0.0);
    printStatus(sArr);

    sArr.set(5, 5.0);
    printStatus(sArr);

    sArr.set(9, 6.0);
    printStatus(sArr);

    sArr.add(0.0);
    printStatus(sArr);

    printStatus(sArr, 1);
    printStatus(sArr, 2);
    printStatus(sArr, 3);
    printStatus(sArr, 10);
}
