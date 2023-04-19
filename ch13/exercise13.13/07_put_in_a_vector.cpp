#include <iostream>
#include <vector>

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
    std::vector<X> vec(3); // Three objects of type X will be created and put 
                           // in vec, so the default constaructor will be 
			   // called three times.

    std::cout << "----------" << std::endl;
    return 0;
}
// When the program finishes, vec will be destroyed and the three objects of
// type X will be destroyed, too.

// X()
// X()
// X()
// ~X()
// ~X()
// ~X()
