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

void foo(X &parm) {
    std::cout << "void foo(X &parm)" << std::endl;
    return;
}

int main() {
    X obj;  // The default constructor, X(), will be invoked.

    foo(obj); // obj is pass by reference. The copy constructor won't be invoked.

    return 0;
}
// After the program finishes, the destructor, ~X(), of obj will be invoked.

// The following message will be shown in text console.
// X()
// void foo(X &parm)
// ~X()
