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
    Person(const string &name, const string &address) : name(name), address(address) {}

    // delegatign constructor
    Person() : Person("", "") {}

    // Both of the following two constructors have only parameter. They may
    // implicitly convert a string to an object of Person. Therefore, they
    // should be decleared as explicit.
    explicit Person(const string &name) : name(name) {}
    explicit Person(istream &is);

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
