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

    auto midIt = begin(nums) + nums.size() / 2;
    for (auto it = begin(nums); it <= midIt; ++it) {
        if (it != midIt) {
            cout << *it + *(end(nums) - 1 - (it - begin(nums))) << " ";
        } else if (nums.size() % 2 != 0) {
            // We have odd number of elements and at the middle element, now.
            cout << *it;
        }
    }
    cout << endl;

    return 0;
}
