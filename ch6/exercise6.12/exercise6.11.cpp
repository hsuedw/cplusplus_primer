#include <iostream>

using std::cout;
using std::endl;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int x = 12, y = 34;
    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
