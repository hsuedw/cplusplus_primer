#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = { {0, 1, 2, 3},
                     {4, 5, 6, 7},
                     {8, 9, 10, 11}};

    for (int (*r)[4] = ia; r != ia + 3; ++r) {
        for (int *c = *r; c != *r + 4; ++c) {
            cout << *c << " ";
        }
        cout << endl;
    }

    return 0;
}
