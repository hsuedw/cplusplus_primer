#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;   // a is an int (r is an alias for i, which has type int)a

    const int ci = i, &cr = ci;
    auto b = ci;  // b is an int (top-level const in ci is droped)
    auto c = cr;  // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i;  // d is an int * (& of an int object is int *)
    auto e = &ci; // e is const int * (& of a const object is low-level const)
    auto &g = ci; // g is a const int & that is bound to ci

    std::cout << "a = " << a;
    a = 42;
    std::cout << ", a = " << a << std::endl;

    std::cout << "b = " << b;
    b = 42;
    std::cout << ", b = " << b << std::endl;

    std::cout << "c = " << c;
    c = 42;
    std::cout << ", c = " << c << std::endl;

    /*
     * d is a pointer to int and must be assigned by the address of another int object, so this assignment is illegal.
     * g++ exercise2.34.cpp -o exercise2.34
     * exercise2.34.cpp: In function ‘int main()’:
     * exercise2.34.cpp:27:9: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
     *    27 |     d = 42;
     *       |         ^~
     *       |         |
     *       |         int
     */
    //d = 42;
    int i2 = 123;
    const int ci2 = i;
    std::cout << "d = " << d;
    d = &i2;
    std::cout << ", d = " << d << std::endl;

    /*
     * e is a pionter to const int (const int *), so this assignment is illegal.
     * g++ exercise2.34.cpp -o exercise2.34
     * exercise2.34.cpp: In function ‘int main()’:
     * exercise2.34.cpp:27:9: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
     *   27 |     d = 42;
     *      |         ^~
     *      |         |
     *      |         int
     */
    //e = 42;
    std::cout << "e = " << e;
    e = &ci2;
    std::cout << ", e = " << e << std::endl;

    /*
     * g has type const int & that is bound to ci, so we cannot use g to assigne a value to ci. This assignment is illegal.
     * g++ exercise2.34.cpp -o exercise2.34
     * exercise2.34.cpp: In function ‘int main()’:
     * exercise2.34.cpp:56:7: error: assignment of read-only reference ‘g’
     *    56 |     g = 42;
     *       |     ~~^~~~
     */
    //g = 42;

    return 0;
}
