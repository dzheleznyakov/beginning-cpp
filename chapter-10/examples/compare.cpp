// For Ex10_02.cpp
#include <vector>
#include "compare.h"

double compare::max(const std::vector<double> &data)
{
    double result{data[0]};
    for (const auto value : data)
        if (result < value)
            result = value;
    return result;
}

double compare::min(const std::vector<double> &data)
{
    double result{data[0]};
    for (const auto value : data)
        if (result > value)
            result = value;
    return result;
}
