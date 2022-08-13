#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // -30 * 3 + 21 / 5 = -86
    cout << "(a) -30 * 3 + 21 / 5 = " << -30 * 3 + 21 / 5 << endl;

    // -30 + 3 * 21 / 5 = -18
    cout << "(b) -30 + 3 * 21 / 5 = " << -30 + 3 * 21 / 5 << endl;

    // 30 / 3 * 21 % 5 = 0
    cout << "(c) 30 / 3 * 21 % 5 = " << 30 / 3 * 21 % 5 << endl;

    // -30 / 3 * 21 % 4 = -2
    cout << "(d) -30 / 3 * 21 % 4 = " << -30 / 3 * 21 % 4 << endl;

    return 0;
}
