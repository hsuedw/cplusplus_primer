#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<int>::const_iterator find_target (const vector<int> &nums, const int target)
{
    for (auto it = begin(nums); it != end(nums); ++it) {
        if (*it == target) {
            return it;
        }
    }
    return end(nums);
}

int main()
{
    cout << "Enter an integer: " << endl;

    int target;
    cin >> target;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (find_target(nums, target) != end(nums)) {
        cout << target << " has been found!" << endl;
    } else {
        cout << target << " doesn't exist!" << endl;
    }

    return 0;
}
