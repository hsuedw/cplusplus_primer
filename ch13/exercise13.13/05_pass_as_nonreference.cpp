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

void foo(X parm) {
    std::cout << "void foo(X &parm)" << std::endl;
    return;
}
// After foo finishes, the destructor, ~X(), of obj will be invoked.

int main() {
    X obj;  // The default constructor, X(), will be invoked.

    std::cout << "-------- foo begin" << std::endl;
    foo(obj); // obj is pass by nonreference. The copy constructor will be invoked.
    std::cout << "-------- foo end" << std::endl;

    return 0;
}
// After the program finishes, the destructor, ~X(), of obj will be invoked.

// The following message will be shown in text console.
// X()
// X(const X&)
// void foo(X &parm)
// ~X()
// ~X()
