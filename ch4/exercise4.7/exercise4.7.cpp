#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int x = INT_MAX;
    cout << "x = " << x << ", x + 1 = " << x + 1 << endl;

    int y = INT_MIN;
    cout << "y = " << y << ", y - 1 = " << y - 1 << endl;

    unsigned int z = UINT_MAX;
    cout << "z = " << z << ", z + 1 = " << z + 1 << endl;

    return 0;
}
