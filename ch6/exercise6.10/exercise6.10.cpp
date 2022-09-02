#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 12, b = 34;
    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swap(&a, &b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}
