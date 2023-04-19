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
    // This is a pointer. The default constructor, X(), won't be invoked.
    X *obj = nullptr;

    std::cout << "---------- dynamically allocate" << std::endl;
    obj = new X(); // The default constructor, X(), will be invoked.

    std::cout << "---------- destroy the object" << std::endl;
    delete obj;    // The destructor, ~X(), will be invoked.
    obj = nullptr;

    std::cout << "---------- program finishes" << std::endl;
    return 0;
}

// The following message will be shown in text console.
// ---------- dynamically allocate
// X()
// ---------- destroy the object
// ~X()
// ---------- program finishes
