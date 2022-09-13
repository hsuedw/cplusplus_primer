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
    Person person1;
    cout << "person1: name: " << person1.getName() 
         << ", address: " << person1.getAddress() << endl;
   
    Person person2("John");
    cout << "person2: name: " << person2.getName() 
         << ", address: " << person2.getAddress() << endl;
 
    Person person3("Jane", "Taipei Taiwan");
    cout << "person3: name: " << person3.getName() 
         << ", address: " << person3.getAddress() << endl;

    cout << "Please input the data of a person: ";
    Person person4(cin);
    cout << "person4: name: " << person4.getName() 
         << ", address: " << person4.getAddress() << endl;

    return 0;
}
