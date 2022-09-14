#include <iostream>
#include "Person.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

istream &read(istream &is, Person &person)
{
    is >> person.name;
    getline(is, person.address);
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.name << " | " << person.address;
    return os;
}

int main()
{
    Person person;
    if (read(cin, person)) {
        print(cout, person) << endl;
    } else {
        cerr << "No data!" << endl;
    }

    return 0;
}
