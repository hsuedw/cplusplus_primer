#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::ostream;
using std::cout;
using std::endl;

template <typename T> ostream &operator<<(ostream &os, vector<T> &nums)
{
    for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
        os << nums[i];
	if (i != nums.size() - 1) {
            os << ", ";
	}
    }
    return os;
}

int main()
{
    list<int> org1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> org2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    vector<double> copy1(begin(org1), end(org1));
    cout << "copy1: " << copy1 << endl;

    vector<double> copy2(begin(org2), end(org2));
    cout << "copy2: " << copy2 << endl;

    return 0;
}
