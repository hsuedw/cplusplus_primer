#include <string>
#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {}

    // copy constructor
    HasPtr(const HasPtr &rhs) : i(rhs.i) {
        ps = new std::string();

	int n = rhs.ps->size();
	for (int i = 0; i < n; ++i) {
	    ps->push_back(rhs.ps->at(i));
        }
    }

    std::string get() { return *ps; }
    void set(const std::string &s) { *ps = s; }
private:
    std::string *ps;
    int i;
};


int main()
{
    HasPtr obj1= std::string("Edward");
    HasPtr obj2 = obj1;

    std::cout << obj1.get() << " " << obj2.get() << std::endl;

    obj2.set("Angus");
    std::cout << obj1.get() << " " << obj2.get() << std::endl;


    return 0;
}
