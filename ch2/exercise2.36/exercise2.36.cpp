#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
    int a = 3, b = 4;     // a and b have type int. a and b are initialized to 3 and 4, repectively.
    std::cout << "1.1 The type of a: " << typeid(a).name() << ", a = " << a << std::endl;
    std::cout << "1.2 The type of b: " << typeid(b).name() << ", b = " << b << std::endl;

    decltype(a) c = a;    // c has type int and it is initialized to 3, which is the value of a.
    std::cout << "2 The type of c: " << typeid(c).name() << ", c = " << c << std::endl;

    decltype((b)) d = a;  // d is int & and it refers to a.
    std::cout << "3 The type of d: " << typeid(d).name() << ", d = " << d << std::endl;

    std::cout << "4.1 c = " << c << std::endl;
    ++c;                  // c will become 4
    std::cout << "4.2 c = " << c << std::endl;

    std::cout << "5.1 a = " << a << ", d = " << d << std::endl;
    ++d;                  // a will become 4
    std::cout << "5.2 a = " << a << ", d = " << d << std::endl;

    return 0;
}
