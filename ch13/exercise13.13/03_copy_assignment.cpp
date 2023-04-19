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
    X obj1;  // The default constructor, X(), will be invoked.
    X obj2 = obj1;  // The copy constructor, X(const X&), will be invoked.

    obj2 = obj1; // The copy-assignment operator will be invoked.

    return 0;
}
// After the program finishes, the destructor, ~X(), of obj1 and obj2 will be invoked.

// The following message will be shown in text console.
// X()
// X(const X&)
// X &operator=(const X &rhs)
// ~X()
// ~X()
