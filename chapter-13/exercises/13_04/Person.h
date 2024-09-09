#ifndef PERSON_H
#define PERSON_H

#include "string"

using std::string;

class Person
{
private:
    int age;
    string name;
    string gender;

public:
    Person(int av, string nv, string gv) : age{av}, name{nv}, gender{gv} {}

    Person(const Person &person) : age{person.age}, name{person.name}, gender{person.gender} {}

    int getAge() const { return age; }
    string getName() const { return name; }
    string getGender() const { return gender; }
};

#endif
