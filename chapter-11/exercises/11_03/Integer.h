#ifndef INTEGER_11_03
#define INTEGER_11_03

class Integer
{
private:
    int value;

public:
    Integer(int val) : value{val} {}

    Integer() : value{} {}

    Integer(const Integer &num) : value{num.value} {}

    int getValue() const;

    Integer add(const Integer &other) const;

    Integer subract(const Integer &other) const;

    Integer multiply(const Integer &other) const;
};

#endif
