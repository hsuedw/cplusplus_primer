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

    std::string get() { return *ps; }
    void set(const std::string &s) { *ps = s; }
private:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &rhs) :
    ps(new string(*rhs.ps)), i(rhs.i) {}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    delete ps;
    ps = new std::string(*rhs.ps);
    i = rhs.i;

    return *this;
}

int main()
{
    HasPtr obj1 = std::string("Edward");
    HasPtr obj2 = std::string("Angus");

    std::cout << obj1.get() << " " << obj2.get() << std::endl;

    obj2 = obj1;
    std::cout << obj1.get() << " " << obj2.get() << std::endl;

    return 0;
}
