#include <iostream>

using std::cout;
using std::endl;
using std::hex;

int main()
{
    int x[10];
    int *p = x;

    // Because x is an array of int, sizeof(x) returns the total memory,
    // in bytes, to hold the ten ints. In my machine, we need four bytes 
    // for an int, sizeof(x) returns 40.
    // x can be treated as a pointer to the first elemnt of the array,
    // *x dereference the first element of the array.
    // Therefore, sizeof(*x) returns the size of an int object. In this
    // case, it is four bytes.
    // Thererore, this expression returns 10.
    cout << sizeof(x) / sizeof(*x) << endl;  // prints 10

    // Because p is pointer to int and my CPU is 64-bit architecture,
    // we need eight bytes for a pointer to hold a memory address.
    // *p dereference to an int object. In my machine, we need four bytes
    // for an int. Therefore, this expression returens 2.
    cout << sizeof(p) / sizeof(*p) << endl;  // prints 2

    return 0;
}
