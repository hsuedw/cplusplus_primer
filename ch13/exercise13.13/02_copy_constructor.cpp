#include <iostream>

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X &operator=(const X &rhs) {
        std::cout << "X &operator=(const X &rhs)" << std::endl;
        return *this;
    }
    ~X() {std::cout << "~X()" << std::endl;}
};

int main() {
    X obj1;  // default constructor, X(), will be invoked.
    X obj2(obj1);  // copy constructor, X(const X&), will be invoked.
    X obj3 = obj1;  // copy constructor, X(const X&), will be invoked.

    return 0;
}
// After the program finishes, the destructor, ~X(), of obj1, obj2 and obj3 will
// be invoked.

// The following message will be shown in text console.
// X()
// X(const X&)
// X(const X&)
// ~X()
// ~X()
// ~X()
