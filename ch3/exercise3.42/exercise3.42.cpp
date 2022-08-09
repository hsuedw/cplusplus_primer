#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int ia[ivec.size()];

    cout << "Before copy data into ia: ";
    for (auto &i : ia) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        ia[i] = ivec[i];
    }

    cout << "After copy data into ia: ";
    for (auto &i : ia) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
