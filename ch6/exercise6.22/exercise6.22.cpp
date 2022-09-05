#include <iostream>

using std::cout;
using std::endl;

void swapPtr(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapPtr2(int *&a, int *&b)
{
    int *tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int x = 123, y = 456;
    int *pa = &x, *pb = &y;

    cout << "=== Test for swapPtr: " << endl;
    cout << "Before swap: " << *pa << ", " << *pb << endl;
    swapPtr(&pa, &pb);
    cout << "After swap: " << *pa << ", " << *pb << endl;

    int m = 100, n = 200;
    pa = &m, pb = &n;
    cout << "=== Test for swapPtr2: " << endl;
    cout << "Before swap: " << *pa << ", " << *pb << endl;
    swapPtr2(pa, pb);
    cout << "After swap: " << *pa << ", " << *pb << endl;

    return 0;
}
