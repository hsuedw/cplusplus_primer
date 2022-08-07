#include <iterator>
#include <iostream>
using namespace std;

int main()
{
    int ia1[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int ia2[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    auto p1 = begin(ia1) + 2, p2 = begin(ia2) + 4;

    cout << "BEFORE: p1(" << p1 << "): " << *p1 << ", p2(" << p2 <<"): " << *p2 << endl;

    //p1 += p2 - p1; // OK
    p1 = p1 + (p2 - p1);  // OK

    cout << "AFTER: p1(" << p1 << "): " << *p1 << ", p2(" << p2 <<"): " << *p2 << endl;

    return 0;
}
