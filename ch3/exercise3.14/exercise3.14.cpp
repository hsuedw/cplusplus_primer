#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec;
    int n;
    while (cin >> n) {
        vec.push_back(n);
    }

    for (auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
