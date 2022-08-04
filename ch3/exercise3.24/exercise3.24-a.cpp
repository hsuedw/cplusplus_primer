#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }

    for (auto it = begin(nums); it < end(nums); it += 2) {
        if (it + 1 != end(nums)) {
            cout << *it + *(it + 1) << " ";
        } else {
            // We have odd number of elements and at the last element.
            cout << *it;
        }
    }
    cout << endl;

    return 0;
}
