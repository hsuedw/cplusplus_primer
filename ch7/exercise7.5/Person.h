#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

using std::string;

struct Person {
    string name;
    string address;

    string getName() const { return name; }
    string getAddress() const { return address; }
};

#endif // __PERSON_H__