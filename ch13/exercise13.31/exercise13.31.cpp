
// This solution (Exercise 13.31) is modified from Exercise 13.30

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

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

    bool operator<(const HasPtr &) const;

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

bool HasPtr::operator<(const HasPtr &rhs) const {

    return *ps < *rhs.ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    cout << "swapping \"" << *lhs.ps << "\" and \"" << *rhs.ps << "\"" << endl;

    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    vector<HasPtr> objs;

    objs.push_back(HasPtr("John"));
    objs.push_back(HasPtr("Hellen"));
    objs.push_back(HasPtr("Alice"));
    objs.push_back(HasPtr("Edward"));
    objs.push_back(HasPtr("Angus"));
    objs.push_back(HasPtr("Nancy"));
    objs.push_back(HasPtr("Kate"));

    for (auto &obj : objs) {
        cout << *obj << " ";
    }
    cout << endl;

    cout << "After sorting ..." << endl;
    sort(objs.begin(), objs.end());
    for (auto &obj : objs) {
        cout << *obj << " ";
    }
    cout << endl;

    return 0;
}
