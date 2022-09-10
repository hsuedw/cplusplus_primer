#include <vector>
#include <iostream>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;

//typedef int funcType(int, int);
using funcType = int (int, int);

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
    vector<funcType *> vecFunc2 = {add, substract, multiply, divide};
    int a = 456, b = 123;

    for (auto f : vecFunc2) {
        cout << f(a, b) << endl;
    }

    return 0;
}
