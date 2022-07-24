#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a = 3, b = 4;      // a and b have type int. a and b are initialized to 3 and 4, respectively.
    std::cout << "1.1 The type of a: " << typeid(a).name() << ", a = " << a << std::endl;
    std::cout << "1.2 The type of b: " << typeid(b).name() << ", b = " << b << std::endl;

    decltype(a) c = a; // c has type int and it is initialized to 3, which is the value of a.
    //decltype(a) c;     // OK. But c is not initialized.
    std::cout << "2 The type of c: " << typeid(c).name() << ", c = " << c << std::endl;

    decltype(a = b) d = a; // d is int& and it refers to a.
    //decltype(a = b) d;     // Error! d is a reference to int, so it must be initialized.
    std::cout << "3 The type of d: " << typeid(d).name() << ", d = " << d << std::endl;

    return 0;
}
