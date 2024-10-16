#ifndef MYTROUBLES_H
#define MYTROUBLES_H

#include <string>

using std::string;

class Trouble
{
private:
    string message;

public:
    Trouble(string str = "There's a problem") : message{str} {}

    virtual ~Trouble() {}
    virtual string what() const { return message; }
};

class MoreTrouble : public Trouble
{
public:
    MoreTrouble(string str = "There's more trouble...") : Trouble{str} {}
};

class BigTrouble : public MoreTrouble
{
public:
    BigTrouble(string str = "Really big trouble...") : MoreTrouble{str} {}
};

#endif
