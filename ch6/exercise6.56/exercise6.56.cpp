#include <vector>
#include <iostream>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;

//typedef int funcType(int, int);
using funcType = int (int, int);
using funcPtr = int (*)(int, int);

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    assert(b != 0);
    return a / b;
}

int main(int argc, char *argv[])
{
    vector<funcType *> vecFunc = {add, substract, multiply, divide};
    int a = 456, b = 123;

#if 0
    // auto is deduced to funcType *, which is an aliase of int (*)(int, int).
    for (funcType *f : vecFunc) { 
        cout << f(a, b) << endl;
    }
#endif

#if 0
    // funcPtr is an alias for the pointer to a function type, 
    // int (*)(int, int).
    for (funcPtr f: vecFunc) {
        cout << f(a, b) << endl;
    }
#endif

#if 0
    // This for head works as well, although it looks complicated.
    for (int (*f)(int, int) : vecFunc) { 
        cout << f(a, b) << endl;
    }
#endif

    for (auto f : vecFunc) {
        cout << f(a, b) << endl;
    }

    return 0;
}
