#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HasPtr {
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0), use(new size_t(1)) {}

    // copy constructor
    HasPtr(const HasPtr &);

    // copy-assignment operator
    HasPtr &operator=(const HasPtr &);

    string &operator*();

    // destructor
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};

// copy constructor
HasPtr::HasPtr(const HasPtr &rhs) : 
    ps(rhs.ps), i(rhs.i), use(rhs.use) {
    ++*use;
}

// copy-assignment operator
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    --*use;
    if (*use <= 0) {
        delete ps;
	delete use;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;

    return *this;
}

string &HasPtr::operator*() {
    return *ps;
}

// destructor
HasPtr::~HasPtr() {
    --*use;
    if (*use <= 0) {
        delete ps;
        delete use;
    }
}


int main() {
    HasPtr obj1("Hello World!");
    HasPtr obj2(obj1);
    HasPtr obj3 = obj1;

    cout << "----- copy constructor --------" << endl;
    cout << "obj1: " << *obj1 << endl;
    cout << "obj2: " << *obj2 << endl;
    cout << "obj3: " << *obj3 << endl;

    HasPtr obj4("Hello Edward");
    obj2 = obj4;
    cout << "----- copy-assignment operator --------" << endl;
    cout << "obj1: " << *obj1 << endl;
    cout << "obj2: " << *obj2 << endl;
    cout << "obj4: " << *obj4 << endl;

    return 0;
}
