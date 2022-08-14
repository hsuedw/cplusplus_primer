#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i;
    double d;

    d = i = 3.5; // i is 3 (int), d is 3.0 (double)
    cout << "d = " << d << ", i = " << i << endl;

    i = d = 3.5; // d is 3.5 (double), i is 3 (int)
    cout << "d = " << d << ", i = " << i << endl;

    return 0;
}
