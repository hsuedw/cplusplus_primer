#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
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
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vec3 = {1, 2, 3, 4, 5};
    vector<int> vec4 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> vec5 = {1, 2, 3, 4, 5, 7, 6};


    cout << (vec1 == vec2) << endl;
    cout << (vec1 == vec3) << endl;
    cout << (vec1 == vec4) << endl;
    cout << (vec1 == vec5) << endl;

    return 0;
}
