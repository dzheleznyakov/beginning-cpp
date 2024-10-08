#include "BaseLength.h"

std::ostream &operator<<(std::ostream &stream, const BaseLength &length)
{
    stream << length.getValue() << " " << length.getUnit();
    return stream;
}