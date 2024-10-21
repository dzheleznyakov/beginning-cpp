#ifndef DIMENSION_ERROR_H
#define DIMENSION_ERROR_H

#include <stdexcept>
#include <string>

using std::range_error;
using std::string;

class dimension_error : public range_error
{
public:
    using range_error::range_error;

    dimension_error(string str, double dim) : range_error{str + " " + std::to_string(dim)} {}
};

#endif
