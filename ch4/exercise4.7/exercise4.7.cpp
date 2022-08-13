#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int x = INT_MAX;
    cout << x << ", " << x + 1 << endl;

    int y = INT_MIN;
    cout << y << ", " << y - 1 << endl;

    unsigned int z = UINT_MAX;
    cout << z << ", " << z + 1 << endl;

    return 0;
}
