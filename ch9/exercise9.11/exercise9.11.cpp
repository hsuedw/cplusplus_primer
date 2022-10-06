#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::cout;
using std::endl;

ostream &operator<<(ostream &os, vector<int> &nums)
{
    for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
        os << nums[i];
	if (i != nums.size() - 1) {
            os << ", ";
	}
    }
    return os;
}

int main()
{
    // nums1 holds ten ints. Each is initialized to 0.
    vector<int> nums1(10);
    cout << "nums1: " << nums1 << endl;

    // nums2 holds ten ints. Each is initialzed to 2.
    vector<int> nums2(10, 2);
    cout << "nums2: " << nums2 << endl;

    // nums3 holds ten ints. They are initilaized by the list initializer.
    vector<int> nums3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    cout << "nums3: " << nums3 << endl;

    // nums4 holds ten ints. They have the same values in nums3.
    vector<int> nums4(begin(nums3), end(nums3));
    cout << "nums4: " << nums4 << endl;

    // nums5 has four ints. We use the first four elements in nums3 to
    // initialize them.
    vector<int> nums5(begin(nums3), begin(nums3) + 4);
    cout << "nums5: " << nums5 << endl;

    // nums6 is a copy of nums3.
    vector<int> nums6(nums3);
    cout << "nums6: " << nums6 << endl;

    return 0;
}
