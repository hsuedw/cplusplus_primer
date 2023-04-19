
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Employee {
public:
    Employee() : id(nextId++), name("no name") {}
    Employee(const string &name) : id(nextId++), name(name) {}

    unsigned int getId() { return id; }
    string getName() { return name; }
    unsigned int getId() const { return id; }
    string getName() const { return name; }
private:
    static unsigned int nextId;
    unsigned int id;
    string name;
};

unsigned int Employee::nextId = 0;

void printEmployee(const Employee &e) {
    cout << e.getName() << ": " << e.getId() << endl;
}

int main(int argc, char **argv) {
    Employee noName, john("John"), angus("Angus");

    printEmployee(noName);
    printEmployee(john);
    printEmployee(angus);

    return 0;
}
