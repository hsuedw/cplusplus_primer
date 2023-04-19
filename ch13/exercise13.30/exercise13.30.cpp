
// This solution (Exercise 13.30) is modified from Exercise 13.22

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
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

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    cout << "swapping \"" << *lhs.ps << "\" and \"" << *rhs.ps << "\"" << endl;

    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    HasPtr obj1("Hello World!");
    HasPtr obj2("Good morning!");

    cout << "obj1: " << *obj1 << endl;
    cout << "obj2: " << *obj2 << endl;

    swap(obj1, obj2);

    cout << "obj1: " << *obj1 << endl;
    cout << "obj2: " << *obj2 << endl;

    return 0;
}
