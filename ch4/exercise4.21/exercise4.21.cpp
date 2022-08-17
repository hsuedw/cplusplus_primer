#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    constexpr int sz = 10, max_val = 200;
    vector<int> vec(sz);

    srand((unsigned int)time(NULL));
    cout << "The original data: ";
    for (int i = 0; i < sz; ++i) {
        int x = rand() % max_val;
        cout << x << " ";
	vec[i] = x;
    }
    cout << endl;

    for (auto &x : vec) {
        x = (x & 1) ? (x << 1) : x;
    }
    cout << "The modified data: ";
    for (const auto &x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
