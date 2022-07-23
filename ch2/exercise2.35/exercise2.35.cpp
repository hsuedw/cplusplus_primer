#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;
    std::cout << "i has type: " << typeid(i).name() << std::endl;
    std::cout << "-----------------------" << std::endl;

    auto j = i;
    std::cout << "j has type: " << typeid(j).name() << std::endl;
    std::cout << "j = " << j;
    j = 100;
    std::cout << ", j = " << j << std::endl;
    std::cout << "-----------------------" << std::endl;

    const auto &k = i;
    std::cout << "k has type: " << typeid(k).name() << std::endl;
    //k = 100;
    /*
     * g++ exercise2.35.cpp -o exercise2.35
     * exercise2.35.cpp: In function ‘int main()’:
     * exercise2.35.cpp:17:7: error: assignment of read-only reference ‘k’
     *    17 |     k = 100;
     *       |     ~~^~~~~
     */
    std::cout << "-----------------------" << std::endl;

    auto *p = &i;
    std::cout << "p has type: " << typeid(p).name() << std::endl;
    //*p = 123;
    /*
     * g++ exercise2.35.cpp -o exercise2.35
     * exercise2.35.cpp: In function ‘int main()’:
     * exercise2.35.cpp:28:8: error: assignment of read-only location ‘* p’
     *    28 |     *p = 123;
     *       |     ~~~^~~~~
     */
    int x = 123;
    std::cout << "p = " << p << ", *p = " << *p;
    p = &x;
    std::cout << ", p = " << p << ", *p = " << *p << std::endl;
    //*p = 456;
    /*
     * g++ exercise2.35.cpp -o exercise2.35
     * exercise2.35.cpp: In function ‘int main()’:
     * exercise2.35.cpp:40:8: error: assignment of read-only location ‘* p’
     *    40 |     *p = 456;
     *       |     ~~~^~~~~
     */
    std::cout << "-----------------------" << std::endl;

    const auto j2 = i, &k2 = i;
    std::cout << "j2 has type: " << typeid(j2).name() << std::endl;
    std::cout << "k2 has type: " << typeid(k2).name() << std::endl;
    std::cout << "address of j2 = " << &j2 << ", address of the object to which k2 bounds = " << &k2 << ", address of i = " << &i << std::endl;

    //j2 = 100;
    /*
     * g++ exercise2.35.cpp -o exercise2.35
     * exercise2.35.cpp: In function ‘int main()’:
     * exercise2.35.cpp:58:8: error: assignment of read-only variable ‘j2’
     *    58 |     j2 = 100;
     *       |     ~~~^~~~~
     */

    //k2 = 200;
    /*
     * g++ exercise2.35.cpp -o exercise2.35
     * exercise2.35.cpp: In function ‘int main()’:
     * exercise2.35.cpp:67:8: error: assignment of read-only reference ‘k2’
     *   67 |     k2 = 200;
     *      |     ~~~^~~~~
      */
    std::cout << "-----------------------" << std::endl;

    return 0;
}
