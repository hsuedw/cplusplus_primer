#include <iostream>

int main()
{
    int ival1 = 100, ival2 = 200;
    int *p = &ival1;
    std::cout << p << ", "  << *p << std::endl;

    p = &ival2;   /* Change the value of a pointer. */
    std::cout << p << ", "  << *p << std::endl;

    *p = 123;      /* Change the value to which the pointer points. */
    std::cout << p << ", "  << *p << std::endl;

    return 0;
}
