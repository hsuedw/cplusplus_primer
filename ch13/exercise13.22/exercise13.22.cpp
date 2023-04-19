#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HasPtr {
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0) {}

    // copy constructor
    HasPtr(const HasPtr &);

    // copy-assignment operator
    HasPtr &operator=(const HasPtr &);
    HasPtr &operator=(const string &);

    string &operator*();

    // destructor
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &rhs) {
    ps = new string(*rhs.ps);
    i = rhs.i;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    delete ps;

    string *newPs = new string(*rhs.ps);
    ps = newPs;
    i = rhs.i;

    return *this;
}

HasPtr& HasPtr::operator=(const string &s) {
    *ps = s;
    return *this;
}

string& HasPtr::operator*() {
    return *ps;
}

HasPtr::~HasPtr() {
    delete ps;
}

int main() {
    HasPtr obj1("Hello World!");
    HasPtr obj2(obj1);
    HasPtr obj3 = obj1;

    cout << "----- copy constructor --------" << endl;
    cout << "obj1: " << *obj1 << endl;
    cout << "obj2: " << *obj2 << endl;
    cout << "obj3: " << *obj3 << endl;

    cout << "----- copy-assignment operator 1 --------" << endl;
    HasPtr obj4("Good Morning");
    obj1 = obj4;
    cout << "obj1: " << *obj1 << endl;
    cout << "obj4: " << *obj4 << endl;

    cout << "----- copy-assignment operator 2 --------" << endl;
    obj1 = "abc";
    cout << "obj1: " << *obj1 << endl;
    cout << "obj4: " << *obj4 << endl;

    return 0;
}
