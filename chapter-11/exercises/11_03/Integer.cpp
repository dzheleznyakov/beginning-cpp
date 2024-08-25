#include "Integer.h"

int Integer::getValue() const
{
    return value;
}

Integer Integer::add(const Integer &other) const
{
    return Integer{value + other.value};
}

Integer Integer::subract(const Integer &other) const
{
    return Integer{value - other.value};
}

Integer Integer::multiply(const Integer &other) const
{
    return Integer{value * other.value};
}
