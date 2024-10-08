#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <memory>

#include "BaseLength.h"
#include "Inches.h"
#include "Meters.h"
#include "Yards.h"
#include "Perches.h"

template <typename T>
using ptr = std::shared_ptr<T>;

namespace converters
{
    Inches toInches(ptr<BaseLength> length);
    Meters toMeters(ptr<BaseLength> length);
    Yards toYards(ptr<BaseLength> length);
    Perches toPerches(ptr<BaseLength> length);
}

#endif
