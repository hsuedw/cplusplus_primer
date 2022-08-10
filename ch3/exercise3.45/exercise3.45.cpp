#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = { {0, 1, 2, 3},
                     {4, 5, 6, 7},
                     {8, 9, 10, 11}};

    for (auto &r : ia) {
        for (auto &c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 4; ++c) {
            cout << ia[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto r = ia; r != ia + 3; ++r) {
        for (auto c = *r; c != *r + 4; ++c) {
            cout << *c << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
