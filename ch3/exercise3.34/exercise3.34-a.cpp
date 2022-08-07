#include <iterator>
#include <iostream>
using namespace std;

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto p1 = begin(ia) + 2, p2 = begin(ia) + 4;
    //auto p1 = begin(ia) + 5, p2 = begin(ia) + 3;

    cout << "BEFORE: p1(" << p1 << "): " << *p1 << ", p2(" << p2 <<"): " << *p2 << endl;

    p1 += p2 - p1; // OK
    //p1 = p1 + (p2 - p1);  // OK
 
    //p1 = p1 + p2 - p1; // ERROR
    /*
     * g++ exercise3.34.cpp -std=c++11 -Wall -Og -o exercise3.34
     * exercise3.34.cpp: In function ‘int main()’:
     * exercise3.34.cpp:12:13: error: invalid operands of types ‘int*’ and ‘int*’ to binary ‘operator+’
     *   12 |     p1 = p1 + p2 - p1;
     *      |          ~~ ^ ~~
     *      |          |    |
     *      |          int* int*
     */

    cout << "AFTER: p1(" << p1 << "): " << *p1 << ", p2(" << p2 <<"): " << *p2 << endl;

    return 0;
}
