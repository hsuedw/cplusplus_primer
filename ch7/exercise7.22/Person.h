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
friend istream &read(istream &is, Person &person);
friend ostream &print(ostream &os, const Person &person);
	
public:
    Person() = default;
    Person(const string &name) : name(name) {}
    Person(const string &name, const string &address) : name(name), address(address) {}
    Person(istream &is);

    string getName() const { return name; }
    string getAddress() const { return address; }
    void setName(const string& n) { name = n; }

private:
    string name;
    string address;
};

Person::Person(istream &is)
{
    read(is, *this);
}

#endif // __PERSON_H__
