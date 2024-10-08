#include "converters.h"

Inches converters::toInches(ptr<BaseLength> length)
{
    return Inches{length->getValueMm() / MM_PER_INCH};
}

Meters converters::toMeters(ptr<BaseLength> length)
{
    return Meters{length->getValueMm() / MM_PER_METER};
}

Yards converters::toYards(ptr<BaseLength> length)
{
    return Yards{length->getValueMm() / MM_PER_YARD};
}

Perches converters::toPerches(ptr<BaseLength> length)
{
    return Perches{length->getValueMm() / MM_PER_PERCH};
}
