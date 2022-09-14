#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Person {
    string name;
    string address;

    string getName() const { return name; }
    string getAddress() const { return address; }
};

istream &read(istream &is, Person &person);
ostream &print(ostream &os, const Person &person);

#endif // __PERSON_H__
