#include <iostream>

using std::cout;
using std::endl;
using std::hex;

int main()
{
    unsigned long ul1 = 3, ul2 = 7;

    // (a) ul1 & ul2 yields 3.
    cout << (ul1 & ul2) << endl;

    // (b) ul1 | ul2 yields 7.
    cout << (ul1 | ul2) << endl;

    // (c) ul1 && ul2 yields 1 (true).
    cout << (ul1 && ul2) << endl;

    // (d) ul1 || ul2 yields 1 (true).
    cout << (ul1 && ul2) << endl;

    return 0;
}
