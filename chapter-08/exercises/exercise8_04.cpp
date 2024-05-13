/*
    Create a function plus() that adds two values and returns their sum.
    Provide overloaded versions to work with int, double and string types,
    and test that they work.
*/
#include <iostream>
#include <string>

using std::string;

int plus(int a, int b);
double plus(const double &a, const double &b);
string plus(const string &a, const string &b);

int main()
{
    int n{plus(3, 4)};
    double d{plus(3.2, 4.2)};
    // int d1{plus(3, 4.2)}; -- won't compile
    string s{plus("he", "llo")};
    string s1{"aaa"};
    string s2{"bbb"};
    string s3{plus(s1, s2)};

    std::cout << "3 + 4 = " << n << std::endl;
    std::cout << "3.2 + 4.2 = " << d << std::endl;
    std::cout << "he + llo = " << s << std::endl;
    std::cout << "aaa + bbb = " << s3 << std::endl;
}

int plus(int a, int b)
{
    return a + b;
}

double plus(const double &a, const double &b)
{
    return a + b;
}

string plus(const string &a, const string &b)
{
    string result{a + b};
    return result;
}
