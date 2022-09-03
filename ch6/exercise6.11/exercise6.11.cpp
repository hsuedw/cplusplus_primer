#include <iostream>

using std::cout;
using std::endl;

void reset(int &x)
{
    x = 0;
}

int main()
{
    int x = 123;
    cout << "Before reset, x = " << x << endl;

    reset(x);
    cout << "After reset, x = " << x << endl;

    return 0;
}
