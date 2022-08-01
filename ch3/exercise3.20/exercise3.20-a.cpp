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

    for (int i = 0; i < nums.size(); i += 2) {
        if (i + 1 != nums.size()) {
            cout << nums[i] + nums[i + 1] << " ";
        } else {
            // We have odd number of elements and at the last element.
            cout << nums[i];
        }
    }
    cout << endl;

    return 0;
}
