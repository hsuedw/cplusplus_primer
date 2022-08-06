#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;
    constexpr decltype(vec.size()) sz = 10;

    for (decltype(vec.size()) i = 0; i < sz; ++i) {
        vec.push_back(i);
    }

    vector<int> vec2 = vec;

    cout << "values in vec: ";
    for (auto &x : vec) {
        cout << x << " ";
    }
    cout << endl;

    cout << "values in vec2: ";
    for (auto &x : vec2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
