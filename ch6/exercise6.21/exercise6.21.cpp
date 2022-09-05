#include <iostream>

using std::cout;
using std::endl;

int max(const int v, const int * const pv)
{
    return (v > *pv) ? v : *pv;
}

int main()
{
    int x = 100;
    cout << max(123, &x) << endl;
    cout << max(23, &x) << endl;

    return 0;
}
