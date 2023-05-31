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

#if 0
// This implementation is wrong. We need to copyt the 
// data from rhs first. Then, update the lhs.
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    delete ps;

    string *newPs = new string(*rhs.ps);
    ps = newPs;
    i = rhs.i;

    return *this;
}
#else
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    string *newPs = new string(*rhs.ps);
    delete ps;
    ps = newPs;
    i = rhs.i;

    return *this;
}
#endif

#if 0
// This implementation is wrong. We need to copy the 
// data from rhs first. Then, update the lhs.
HasPtr& HasPtr::operator=(const string &s) {
    *ps = s;
    return *this;
}
#else
HasPtr& HasPtr::operator=(const string &rhs) {
    string *newPs = new string(rhs);
    delete ps;
    ps = newPs;

    return *this;
}
#endif

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

    cout << "----- assign obj4 to obj1 --------" << endl;
    HasPtr obj4("Good Morning");
    obj1 = obj4;
    cout << "obj1: " << *obj1 << endl;
    cout << "obj4: " << *obj4 << endl;

    cout << "----- assign obj1 to a string literal --------" << endl;
    obj1 = "abc";
    cout << "obj1: " << *obj1 << endl;
    cout << "obj4: " << *obj4 << endl;

    cout << "----- assign obj1 to a string --------" << endl;
    string test = "Hello Angus";
    obj1 = test;
    cout << "obj1: " << *obj1 << endl;

    cout << "----- assign obj1 to itself --------" << endl;
    obj1 = obj1;
    cout << "obj1: " << *obj1 << endl;

    return 0;
}
