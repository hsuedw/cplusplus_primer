#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

template <typename T> ostream &operator<<(ostream &os, vector<T> vec) 
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        cout << vec[i];
	if (i + 1 != vec.size()) {
            cout << " ";
	}
    }
    return os;
}

int main(int argc, char *argv[])
{
    int target;
    cout << "Please input the target number to count: " << endl;
    cin >> target;

    cout << "Please input a sequence of integers: " << endl;
    int x;
    vector<int> nums;
    while (cin >> x) {
        nums.push_back(x);
    }

    cout << "The integer " << target << " happens "  << count(begin(nums), end(nums), target) <<  " time(s) in the input sequence." << endl;

    return 0;
}
