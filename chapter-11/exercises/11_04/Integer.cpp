#include "Integer.h"

int compare(const Integer1 one, const Integer1 another)
{
    if (one.value < another.value)
        return -1;
    if (one.value == another.value)
        return 0;
    return 1;
}

int compare(const Integer2 &one, const Integer2 &another)
{
    if (one.value < another.value)
        return -1;
    if (one.value == another.value)
        return 0;
    return 1;
}
