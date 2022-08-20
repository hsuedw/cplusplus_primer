#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    bool someValue = true;
    int x = 100, y = 200;
    someValue ? ++x, ++y : --x, --y;
    cout << "x = " << x << ", y = " << y << endl;

    someValue = false;
    x = 100, y = 200;
    someValue ? ++x, ++y : --x, --y;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
