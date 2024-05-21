/*
    Define the plus() function from Exercise 8_04 as a template,
    and test that it works for numeric types. Does your template work
    for the statement plus("he", "llo")? Can you explain this behaviour?
    Suggest a solution for the problem.
*/
#include <iostream>
#include <string>

using std::string;

template <typename T>
T plus(T a1, T a2);

string plus(const string &s1, const string &s2);

int main()
{
    int i1{3}, i2{4};
    long l1{3}, l2{4};
    unsigned long long ull1{3}, ull2{4};
    double d1{3.5}, d2{4.7};
    long double ld1{3.5}, ld2{4.7};

    std::cout << "Integer: " << i1 << " + " << i2 << " = " << plus(i1, i2) << std::endl;
    std::cout << "Long: " << l1 << " + " << l2 << " = " << plus(l1, l2) << std::endl;
    std::cout << "Unsigned Long Long: " << ull1 << " + " << ull2 << " = " << plus(ull1, ull2) << std::endl;
    std::cout << "Double: " << d1 << " + " << d2 << " = " << plus(d1, d2) << std::endl;
    std::cout << "Long Double: " << ld1 << " + " << ld2 << " = " << plus(ld1, ld2) << std::endl;
    std::cout << "C++ String: \"he\" + \"llo\" = " << plus("he", "llo") << std::endl;
}

template <typename T>
T plus(T a1, T a2)
{
    return a1 + a2;
}

string plus(const string &s1, const string &s2)
{
    return s1 + s2;
}
