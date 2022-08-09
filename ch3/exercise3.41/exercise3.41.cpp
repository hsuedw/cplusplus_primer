#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> ivec(begin(ia), end(ia));

    for (auto &i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
