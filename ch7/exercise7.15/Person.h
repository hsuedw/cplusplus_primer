#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Person;

istream &read(istream &is, Person &person);
ostream &print(ostream &os, const Person &person);

struct Person {
    Person() = default;
    Person(const string &name) : name(name) {}
    Person(const string &name, const string &address) : name(name), address(address) {}
    Person(istream &is);

    string name;
    string address;

    string getName() const { return name; }
    string getAddress() const { return address; }
    void setName(const string& n) { name = n; }
};

Person::Person(istream &is)
{
    read(is, *this);
}

#endif // __PERSON_H__
